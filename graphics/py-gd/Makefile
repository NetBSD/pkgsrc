# $NetBSD: Makefile,v 1.36 2011/11/01 06:01:43 sbd Exp $

DISTNAME=	gdmodule.c
PKGNAME=	${PYPKGPREFIX}-gd-1.3
PKGREVISION=	14
CATEGORIES=	graphics python
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
EXTRACT_SUFX=

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/
COMMENT=	Python interface to gd graphics library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
BUILD_TARGET=	default

EGG_NAME=	${DISTNAME:S/.c/-${PKGVERSION_NOREV}/}

post-patch:
	${SED} 's+@GD_PREFIX@+${BUILDLINK_PREFIX.gd}+g' ${FILESDIR}/Setup.in > ${WRKSRC}/setup.py

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
