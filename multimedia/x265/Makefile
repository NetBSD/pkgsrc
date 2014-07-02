# $NetBSD: Makefile,v 1.1 2014/07/02 11:46:21 adam Exp $

DISTNAME=	1.1
PKGNAME=	x265-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/get/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	x265
WRKSRC=		${WRKDIR}/multicoreware-x265-ae9609aeebdc/source
BUILD_DEPENDS+=	yasm>=1.0.0:../../devel/yasm

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
