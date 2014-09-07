# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:41 obache Exp $

PKGNAME=	suse_libdrm-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libdrm-2.4.26-15.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libdrm

EMUL_MODULES.linux=	x11

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
