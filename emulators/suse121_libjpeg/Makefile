# $NetBSD: Makefile,v 1.5 2015/02/16 10:15:45 jperkin Exp $

PKGNAME=	suse_libjpeg-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libjpeg62-62.0.0-10.4.1.${SUSE_ARCH}
RPMPKGS+=	libjpeg8-8.0.2-8.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
