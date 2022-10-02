# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_freetype2-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libfreetype6-2.10.4-150000.4.12.1.${SUSE_ARCH}
RPMPKGS+=	libbz2-1-1.0.8-150400.1.122.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for freetype-2.x

EMUL_MODULES.linux=	base png

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
