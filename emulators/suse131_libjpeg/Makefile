# $NetBSD: Makefile,v 1.4.4.1 2015/08/01 09:19:55 tron Exp $

PKGNAME=	suse_libjpeg-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libjpeg62-62.0.0-24.4.1.${SUSE_ARCH}
RPMUPDPKGS+=	libjpeg8-8.0.2-24.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
