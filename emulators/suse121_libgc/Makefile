# $NetBSD: Makefile,v 1.1 2015/09/26 00:15:44 kamil Exp $

PKGNAME=	suse_libgc-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libgc1-7.1.9.6-143.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Boehm-Demers-Weiser g/c libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
