# $NetBSD: Makefile,v 1.9 2016/05/28 13:04:28 rjs Exp $

PKGNAME=	suse_libpng-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
RPMUPDPKGS+=	libpng12-0-1.2.50-6.10.1.${SUSE_ARCH}
RPMUPDPKGS+=	libpng16-16-1.6.6-22.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
