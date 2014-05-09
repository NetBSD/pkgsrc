# $NetBSD: Makefile,v 1.10 2014/05/09 07:37:21 wiz Exp $

DISTNAME=	itstool-2.0.2
CATEGORIES=	textproc
MASTER_SITES=	http://files.itstool.org/itstool/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://itstool.org/
COMMENT=	ITS Tool allows you to translate XML documents with PO files
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

REPLACE_PYTHON=	${WRKSRC}/itstool.in

DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2

PYTHON_VERSIONS_INCOMPATIBLE=  33 34 # not yet ported as of 2.0.2
#Traceback (most recent call last):
#  File "/usr/pkg/bin/itstool", line 1516, in <module>
#    doc.apply_its_rules(not(opts.nobuiltins), params=params)
#  File "/usr/pkg/bin/itstool", line 724, in apply_its_rules
#    self.apply_its_file(os.path.join(itsdir, dfile), params=params)
#  File "/usr/pkg/bin/itstool", line 754, in apply_its_file
#    if not nss.has_key(nsdef.name):
#AttributeError: 'dict' object has no attribute 'has_key'

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
