# $NetBSD: Makefile,v 1.1 2025/01/07 19:40:21 vins Exp $

DISTNAME=	hwdata-0.391
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcrhonek/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vcrhonek/hwdata/
COMMENT=	Database of IDs used in PCI, PNP and USB devices
LICENSE=	gnu-gpl-v2 OR mit

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake sed
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	hwdata.pc.in

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--sysconfdir=${PKG_SYSCONFDIR} \
		--mandir=${PREFIX}/${PKGMANDIR} \
		--datarootdir=${PREFIX}/share

MAKE_FLAGS+=	SED=${SED:Q}
MAKE_FLAGS+=	PKGCONFIG_DIR=${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
