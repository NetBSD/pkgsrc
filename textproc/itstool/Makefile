# $NetBSD: Makefile,v 1.22 2022/06/30 11:18:54 nia Exp $

DISTNAME=	itstool-2.0.7
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://files.itstool.org/itstool/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://itstool.org/
COMMENT=	ITS Tool allows you to translate XML documents with PO files
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

# With 27, gnumeric112 fails to build the cs translation with
# ascii/utf-8 confusion.  This is not understood, so just avoid
# python27, as it increasingly seems that no one is using it and
# debugging problems with that version.
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
