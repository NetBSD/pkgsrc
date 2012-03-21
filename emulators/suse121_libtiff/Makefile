# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:38:40 obache Exp $

DISTNAME=	suse_libtiff-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libtiff3-3.9.5-8.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
