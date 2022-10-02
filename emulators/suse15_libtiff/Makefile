# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:19 wiz Exp $

PKGNAME=	suse_libtiff-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libjbig2-2.1-3.2.1.${SUSE_ARCH}
RPMPKGS+=	libtiff5-4.0.9-150000.45.11.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
