# $NetBSD: Makefile,v 1.1 2020/12/09 12:05:58 ryoon Exp $

GITHUB_PROJECT=	sane-airscan
GITHUB_TAG=	0.99.21
DISTNAME=	sane-airscan-0.99.21
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexpevzner/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/alexpevzner/sane-airscan/
COMMENT=	SANE backend for Apple AirScan (eSCL) and WSD
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix config install path
SUBST_FILES.prefix=	meson.build
SUBST_VARS.prefix=	PREFIX

EGDIR=			${PREFIX}/share/examples/
CONF_FILES=		${EGDIR}/airscan.conf ${PREFIX}/etc/sane.d/airscan.conf


.include "../../devel/meson/build.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
