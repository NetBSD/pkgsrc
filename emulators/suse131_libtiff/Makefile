# $NetBSD: Makefile,v 1.5.4.1 2015/08/01 09:19:55 tron Exp $

PKGNAME=	suse_libtiff-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	libjbig2-2.0-10.4.1.${SUSE_ARCH}
RPMUPDPKGS+=	libtiff5-4.0.4-8.10.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
