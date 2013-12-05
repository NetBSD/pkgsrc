# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:14 obache Exp $

DISTNAME=	suse_aspell-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	aspell-0.60.6.1-14.1.4.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for aspell

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
