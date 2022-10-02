# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_libjpeg-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libjpeg62-62.3.0-150400.15.7.${SUSE_ARCH}
RPMPKGS+=	libjpeg8-8.2.2-150400.15.9.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
