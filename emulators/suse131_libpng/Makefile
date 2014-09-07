# $NetBSD: Makefile,v 1.5 2014/09/07 12:26:43 obache Exp $

PKGNAME=	suse_libpng-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libpng12-0-1.2.50-6.4.1.${SUSE_ARCH}
RPMUPDPKGS+=	libpng16-16-1.6.6-12.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
