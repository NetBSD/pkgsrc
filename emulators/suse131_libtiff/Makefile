# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:16 obache Exp $

DISTNAME=	suse_libtiff-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libtiff5-4.0.3-8.1.2.${SUSE_ARCH}
RPMPKGS+=	libjbig2-2.0-10.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
