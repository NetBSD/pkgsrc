# $NetBSD: Makefile,v 1.1.2.1 2014/01/20 23:15:45 tron Exp $

DISTNAME=	suse_libpng-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	libpng12-0-1.2.50-6.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libpng16-16-1.6.6-8.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
