# $NetBSD: Makefile,v 1.27 2025/12/31 09:02:51 wiz Exp $

DISTNAME=	itstool-2.0.7
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	https://files.itstool.org/itstool/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://itstool.org/
COMMENT=	ITS Tool allows you to translate XML documents with PO files
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

# With 27, gnumeric112 fails to build the cs translation with
# ascii/utf-8 confusion.  This is not understood, so just avoid
# python27, as it increasingly seems that no one is using it and
# debugging problems with that version.
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.10.4nb4:../../textproc/py-libxml2

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
