# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:19 wiz Exp $

PKGNAME=	suse_libsystemd-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libgcrypt20-1.9.4-150400.4.6.${SUSE_ARCH}
RPMPKGS+=	libgpg-error0-1.42-150400.1.101.${SUSE_ARCH}
RPMPKGS+=	liblz4-1-1.9.3-150400.1.7.${SUSE_ARCH}
RPMPKGS+=	libsystemd0-249.12-150400.8.10.1.${SUSE_ARCH}
RPMPKGS+=	libzstd1-1.5.0-150400.1.71.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libsystemd

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
