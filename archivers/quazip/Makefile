# $NetBSD: Makefile,v 1.1 2020/05/28 14:15:12 ryoon Exp $

DISTNAME=	quazip-0.9
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=stachenov/}
GITHUB_PROJECT=	quazip
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://stachenov.github.io/quazip/
COMMENT=	Qt/C++ wrapper for Minizip
LICENSE=	gnu-lgpl-v2.1 # with static linking exception

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE=		quazip.pc

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
