# $NetBSD: Makefile,v 1.44 2013/09/04 12:31:25 obache Exp $

DISTNAME=	gdmodule.c
PKGNAME=	${PYPKGPREFIX}-gd-1.3
PKGREVISION=	19
CATEGORIES=	graphics python
MASTER_SITES=	# on ftp.NetBSD.org
EXTRACT_SUFX=

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://newcenturycomputers.net/projects/gdmodule.html
COMMENT=	Python interface to gd graphics library
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}
BUILD_TARGET=	default

EGG_NAME=	${DISTNAME:S/.c/-${PKGVERSION_NOREV}/}

post-patch:
	${SED} 's+@GD_PREFIX@+${BUILDLINK_PREFIX.gd}+g' ${FILESDIR}/Setup.in > ${WRKSRC}/setup.py

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
