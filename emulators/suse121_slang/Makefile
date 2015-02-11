# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:16 obache Exp $

DISTNAME=	suse_slang-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libslang2-2.2.2-6.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for S-Lang

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
