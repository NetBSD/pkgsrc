# $NetBSD: Makefile,v 1.1.1.1 2012/02/10 17:55:15 drochner Exp $
#

DISTNAME=	itstool-1.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://files.itstool.org/itstool/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://itstool.org/
COMMENT=	ITS Tool allows you to translate XML documents with PO files
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

REPLACE_PYTHON=	${WRKSRC}/itstool.in

DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
