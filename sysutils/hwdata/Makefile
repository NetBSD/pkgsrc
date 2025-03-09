# $NetBSD: Makefile,v 1.4 2025/03/09 20:09:55 bsiegert Exp $

DISTNAME=	hwdata-0.393
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

MAKE_FLAGS+=	PKGCONFIG_DIR=${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
