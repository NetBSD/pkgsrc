# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_libpng-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libpng12-0-1.2.57-2.18.${SUSE_ARCH}
RPMPKGS+=	libpng16-16-1.6.34-3.9.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
