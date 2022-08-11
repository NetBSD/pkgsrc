# $NetBSD: Makefile,v 1.25 2022/08/11 05:08:05 gutteridge Exp $

DISTNAME=	suil-0.10.12
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/suil/
COMMENT=	Lightweight C library for loading and wrapping LV2 plugin UIs
LICENSE=	isc

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# Kludge to support rst2man on Mac OS X, PR pkg/49921
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
WAF_ENV+=	LC_ALL="en_US.UTF-8"
.endif

PYTHON_FOR_BUILD_ONLY=	tool
PKGCONFIG_OVERRIDE+=	suil.pc.in

.include "../../devel/waf/waf.mk"
BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.12.0
.include "../../audio/lv2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
