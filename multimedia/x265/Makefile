# $NetBSD: Makefile,v 1.6 2015/02/12 09:02:42 adam Exp $

DISTNAME=	1.5
PKGNAME=	x265-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/get/
DIST_SUBDIR=	x265
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/multicoreware-x265-9f0324125f53/source
BUILD_DEPENDS+=	yasm>=1.0.0:../../devel/yasm

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
