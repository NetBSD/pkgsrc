# $NetBSD: Makefile,v 1.5 2015/02/16 10:15:49 jperkin Exp $

PKGNAME=	suse_libtiff-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	libtiff5-4.0.3-8.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libjbig2-2.0-10.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
