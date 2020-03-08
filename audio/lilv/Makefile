# $NetBSD: Makefile,v 1.20 2020/03/08 16:47:25 wiz Exp $

DISTNAME=	lilv-0.24.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/lilv/
COMMENT=	C library to make the use of LV2 plugins as simple as possible
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	gsed pkg-config

WAF_ENV+=	LV2_PATH=${BUILDLINK_PREFIX.lv2}/lib/lv2
WAF_ARGS+=	--no-bindings

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	lv2bench
.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
# Darwin doesn't have CLOCK_GETTIME so it doesn't compile this
PLIST.lv2bench=	yes
.endif

PYTHON_FOR_BUILD_ONLY=	tool
PKGCONFIG_OVERRIDE+=	lilv.pc.in

.include "options.mk"
.include "../../devel/waf/waf.mk"
BUILDLINK_API_DEPENDS.sratom+=	sratom>=0.4.0
.include "../../converters/sratom/buildlink3.mk"
BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.14.0
.include "../../audio/lv2/buildlink3.mk"
BUILDLINK_API_DEPENDS.sord+=	sord>=0.14.0
.include "../../textproc/sord/buildlink3.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.18.0
.include "../../textproc/serd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
