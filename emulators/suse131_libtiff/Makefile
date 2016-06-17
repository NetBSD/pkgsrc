# $NetBSD: Makefile,v 1.7 2016/06/17 17:21:38 tsutsui Exp $

PKGNAME=	suse_libtiff-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libjbig2-2.0-10.4.1.${SUSE_ARCH}
RPMUPDPKGS+=	libtiff5-4.0.6-8.22.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
