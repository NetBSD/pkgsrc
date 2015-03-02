# $NetBSD: Makefile,v 1.1 2015/03/02 19:14:08 tnn Exp $

PKGNAME=	suse_lsb-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	lsb-4.0-22.3.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Linux Standard Base

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
