# $NetBSD: Makefile,v 1.5 2014/11/29 21:27:06 adam Exp $

DISTNAME=	1.4
PKGNAME=	x265-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/get/
DIST_SUBDIR=	x265
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/multicoreware-x265-5e604833c5aa/source
BUILD_DEPENDS+=	yasm>=1.0.0:../../devel/yasm

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
