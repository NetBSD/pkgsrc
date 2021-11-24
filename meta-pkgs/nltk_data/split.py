#!/usr/bin/env python3

import os
import xml.etree.ElementTree as ET

tree = ET.parse('nltk_data.xml')

root = tree.getroot()

for child in root[0]:
    id = child.attrib["id"]
    path = f"/usr/pkgsrc/textproc/nltk_data-{id}"
    try:
        os.mkdir(path)
    except Exception:
        pass
    name = child.attrib["name"]
    if "webpage" in child.attrib:
        webpage = "HOMEPAGE=\t" + child.attrib["webpage"]
    else:
        webpage = ""
    if "license" in child.attrib:
        license = child.attrib["license"]
    subdir = child.attrib["subdir"]
    url = child.attrib["url"]
    with open(path + "/Makefile", "w") as f:
        print(f"""# $NetBSD: split.py,v 1.1 2021/11/24 15:56:18 wiz Exp $

DISTNAME=	{id}
PKGNAME=	nltk_data-{id}-20211124
CATEGORIES=	textproc
DIST_SUBDIR=	${{PKGNAME_NOREV}}

{webpage}
COMMENT=	NLTK Data - {name}
#LICENSE=	{license}

TYPE=		{subdir}

.include "../../meta-pkgs/nltk_data/common.mk"
.include "../../mk/bsd.pkg.mk"
""", file=f, end='')
    with open(path + "/DESCR", "w") as f:
        print(f"""This package contains data for NLTK, the Natural Language Toolkit.

This package contains data from/for {name}.""", file=f)
    with open(path + "/PLIST", "w") as f:
        print(f"""@comment $NetBSD: split.py,v 1.1 2021/11/24 15:56:18 wiz Exp $
share/nltk/{subdir}/{id}.zip""", file=f)
