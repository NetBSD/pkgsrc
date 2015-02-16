# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:48 jperkin Exp $

PKGNAME=	suse_libjpeg-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libjpeg62-62.0.0-24.1.3.${SUSE_ARCH}
RPMPKGS+=	libjpeg8-8.0.2-24.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
