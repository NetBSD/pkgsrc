# $NetBSD: Makefile,v 1.44 2021/09/10 11:14:05 nia Exp $

DISTNAME=	jack2-1.9.19
PKGNAME=	${DISTNAME:S/jack2/jack/1}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=jackaudio/}
GITHUB_PROJECT=	jack2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://jackaudio.org/
COMMENT=	Low-latency audio server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config bash

WAF_ARGS+=	--systemd=no

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	alsa
.if ${OPSYS} == "Linux"
PLIST.alsa=	yes
.endif

PLIST_VARS+=	boomer oss
.if ${OPSYS} == "SunOS"
PLIST.boomer=	yes
PLIST.oss=	yes
.endif

PLIST_VARS+=	sun
.if ${OPSYS} == "NetBSD"
PLIST.sun=	yes
.endif

REPLACE_PYTHON+=	waf
REPLACE_PYTHON+=	tools/jack_control
REPLACE_BASH+=		svnversion_regenerate.sh

PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGCONFIG_OVERRIDE+=		jack.pc.in

.include "../../lang/python/application.mk"
.include "../../devel/waf/waf.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
