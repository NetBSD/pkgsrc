# $NetBSD: Makefile,v 1.1.1.1.2.1 2012/04/21 16:10:24 tron Exp $

DISTNAME=	suse_libtiff-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libtiff3-3.9.5-8.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
