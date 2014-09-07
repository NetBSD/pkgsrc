# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:43 obache Exp $

PKGNAME=	suse_libjpeg-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libjpeg62-62.0.0-24.1.3.${SUSE_ARCH}
RPMPKGS+=	libjpeg8-8.0.2-24.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
