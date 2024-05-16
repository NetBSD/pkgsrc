# $NetBSD: Makefile,v 1.20 2024/05/16 06:15:03 wiz Exp $

GITHUB_PROJECT=	sane-airscan
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	sane-airscan-0.99.27
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexpevzner/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/alexpevzner/sane-airscan/
COMMENT=	SANE backend for Apple AirScan (eSCL) and WSD
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

EGDIR=			${PREFIX}/share/examples/sane.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/sane.d/dll.d
CONF_FILES=		${EGDIR}/dll.d/airscan ${PKG_SYSCONFDIR}/sane.d/dll.d/airscan
CONF_FILES+=		${EGDIR}/airscan.conf ${PKG_SYSCONFDIR}/sane.d/airscan.conf

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
