#! python
# $NetBSD: fill-placeholders.py,v 1.1 2019/05/05 18:36:05 rillig Exp $

"""
Fills in some sections of data that are determined directly from the
pkgsrc code, such as variable names or help topics.
"""

import filecmp
import os
import re
import sys
from typing import List, Match
from xml.sax.saxutils import escape as to_xml

pkgsrcdir = os.environ['PKGSRCDIR']


def read_lines(filename: str) -> List[str]:
    with open(filename, 'r') as f:
        return f.readlines()


def help_topics() -> str:
    # type="vert" would spread the columns over several pages,
    # starting with aaaa | pppp on the first page, which is
    # unintuitive in both the PDF and the HTML version.
    out = ['<simplelist type="horiz" columns="2">']
    for line in read_lines('help-topics.data')[2:]:
        topic = line.strip()
        out.append(f'<member>{to_xml(topic)}</member>')
    out.append('</simplelist>')

    return '\n'.join(out)


def master_sites() -> str:
    sites = []

    for line in read_lines(f'{pkgsrcdir}/mk/fetch/sites.mk'):
        m = re.match(r'^(MAS\w+)', line)
        if m:
            sites.append(m[1])

    out = ['<simplelist type="horiz" columns="2">']
    for site in sorted(sites):
        out.append(f'<member>{to_xml(site)}</member>')
    out.append('</simplelist>')

    return '\n'.join(out)


def process(filename: str, placeholders: set):
    tmpl_filename = f'{filename}.tmpl'
    tmp_filename = f'{filename}.tmp'
    in_filename = tmpl_filename if os.path.isfile(tmpl_filename) else filename
    out_filename = filename

    phs = dict()
    for p in placeholders:
        phs[p.__name__] = p

    def repl(m: Match):
        return phs[m[1]]() if m[1] in phs else m[0]

    out = []
    for line in read_lines(in_filename):
        out.append(re.sub(r'@(\w+)@', repl, line))

    with open(tmp_filename, 'w') as f:
        f.writelines(out)

    if filecmp.cmp(tmp_filename, out_filename):
        os.remove(tmp_filename)
    elif in_filename == tmpl_filename:
        os.replace(tmp_filename, out_filename)
    else:
        os.rename(out_filename, tmpl_filename)
        os.rename(tmp_filename, out_filename)


def main():
    for filename in sys.argv[1:]:
        process(filename, {help_topics, master_sites})


if __name__ == '__main__':
    main()
