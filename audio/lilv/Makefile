# $NetBSD: Makefile,v 1.37 2023/01/29 21:14:23 ryoon Exp $

DISTNAME=	lilv-0.24.14
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/lilv/
COMMENT=	C library to make the use of LV2 plugins as simple as possible
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	gsed pkg-config

WAF_ARGS+=	--default-lv2-path="~/.lv2/:${BUILDLINK_PREFIX.lv2}/lib/lv2:/usr/local/lib/lv2"
WAF_ARGS+=	--no-bindings

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	lv2bench
.if ${OPSYS} != "Darwin" || ${OPSYS_VERSION} >= 101200
# Darwin doesn't have CLOCK_GETTIME so it doesn't compile this
PLIST.lv2bench=	yes
.endif

PYTHON_FOR_BUILD_ONLY=	tool
PKGCONFIG_OVERRIDE+=	lilv.pc.in

.include "options.mk"
.include "../../devel/waf/waf.mk"
BUILDLINK_API_DEPENDS.sratom+=	sratom>=0.4.0
.include "../../converters/sratom/buildlink3.mk"
BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.18.0
.include "../../audio/lv2/buildlink3.mk"
BUILDLINK_API_DEPENDS.sord+=	sord>=0.14.0
.include "../../textproc/sord/buildlink3.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.30.0
.include "../../textproc/serd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
