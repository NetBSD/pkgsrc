# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:14 obache Exp $

DISTNAME=	suse_aspell-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	aspell-0.60.6.1-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for aspell

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
