# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_libffi-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libffi7-3.2.1.git259-10.8.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libffi

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
