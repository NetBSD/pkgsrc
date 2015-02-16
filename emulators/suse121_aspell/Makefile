# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:44 jperkin Exp $

PKGNAME=	suse_aspell-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	aspell-0.60.6.1-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for aspell

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
