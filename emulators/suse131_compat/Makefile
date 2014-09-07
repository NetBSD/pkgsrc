# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:42 obache Exp $

PKGNAME=	suse_compat-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libstdc++33-3.3.3-41.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with old shared libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
