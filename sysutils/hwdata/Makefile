# $NetBSD: Makefile,v 1.1 2024/12/26 18:33:23 bsiegert Exp $

DISTNAME=	hwdata-0.390
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcrhonek/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/vcrhonek/hwdata/
COMMENT=	Hardware identification and config data
LICENSE=	gnu-gpl-v2 OR x11

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--datarootdir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--disable-blacklist

PKGCONFIG_OVERRIDE+=	hwdata.pc.in

.include "../../mk/bsd.pkg.mk"
