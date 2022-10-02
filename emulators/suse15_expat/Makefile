# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:17 wiz Exp $

PKGNAME=	suse_expat-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libexpat1-2.4.4-150400.3.6.9.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for expat

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
