# $NetBSD: Makefile,v 1.1 2026/03/20 14:07:41 sborrill Exp $

PKGNAME=	suse_gcc12-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	gcc12-12.2.1+git416-150000.1.7.1.${SUSE_ARCH}
RPMPKGS+=	cpp12-12.2.1+git416-150000.1.7.1.${SUSE_ARCH}
RPMPKGS+=	libisl15-0.18-1.443.${SUSE_ARCH}
RPMPKGS+=	libmpc3-1.1.0-1.47.${SUSE_ARCH}
RPMPKGS+=	libmpfr6-4.0.2-3.3.1.${SUSE_ARCH}
RPMPKGS+=	glibc-devel-2.31-150300.46.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GNU GCC 12

EMUL_MODULES.linux=	base binutils

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
