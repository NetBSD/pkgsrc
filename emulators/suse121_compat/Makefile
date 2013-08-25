# $NetBSD: Makefile,v 1.1.1.1.12.1 2013/08/25 16:34:46 tron Exp $

DISTNAME=	suse_compat-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	libstdc++33-3.3.3-30.25.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with old shared libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
