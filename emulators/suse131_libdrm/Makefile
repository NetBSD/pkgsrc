# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:48 jperkin Exp $

PKGNAME=	suse_libdrm-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libdrm2-2.4.46-3.2.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libdrm

EMUL_MODULES.linux=	x11

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
