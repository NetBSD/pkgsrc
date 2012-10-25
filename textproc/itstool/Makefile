# $NetBSD: Makefile,v 1.3 2012/10/25 06:56:00 asau Exp $
#

DISTNAME=	itstool-1.1.2
PKGREVISION=	1
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

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
