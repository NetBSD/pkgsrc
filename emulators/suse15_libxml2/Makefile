# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:19 wiz Exp $

PKGNAME=	suse_libxml2-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libxml2-2-2.9.14-150400.5.7.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxml2

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
