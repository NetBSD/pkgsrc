# $NetBSD: Makefile,v 1.3 2014/09/07 12:26:44 obache Exp $

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
