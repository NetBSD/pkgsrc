# $NetBSD: Makefile,v 1.10 2025/10/13 19:39:30 tnn Exp $

DISTNAME=	hwdata-0.400
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcrhonek/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/vcrhonek/hwdata/
COMMENT=	Hardware identification and config data
LICENSE=	gnu-gpl-v2 OR x11

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake sed
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--datarootdir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--disable-blacklist

PKGCONFIG_OVERRIDE+=	hwdata.pc.in

CHECK_PORTABILITY_SKIP+=	check-usb-ids.sh

MAKE_FLAGS+=	PKGCONFIG_DIR=${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
