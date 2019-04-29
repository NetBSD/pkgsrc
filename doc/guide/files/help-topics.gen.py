#! python
# $NetBSD: help-topics.gen.py,v 1.1 2019/04/29 16:18:41 rillig Exp $

import os

tmpl_file = "help-topics.tmpl.xml"
data_file = "help-topics.data"
out_file = "help-topics.xml"


def merge():
    def read_lines(filename):
        with open(filename) as f:
            return f.readlines()

    out = []
    for tmpl_line in read_lines(tmpl_file):
        if '@topic@' in tmpl_line:
            for topic in read_lines(data_file)[2:]:
                xml_topic = topic.replace('&', '%amp;').replace('<', '&lt;')
                out.append(tmpl_line.replace('@topic@', xml_topic))
        else:
            out.append(tmpl_line)

    with open(f'{out_file}.tmp', 'w') as f:
        f.writelines(out)
    os.rename(f'{out_file}.tmp', out_file)


if __name__ == '__main__':
    merge()
