# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:36:05 obache Exp $

DISTNAME=	suse_compat-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libstdc++33-3.3.3-30.25.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with old shared libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
