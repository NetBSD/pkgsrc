# $NetBSD: Makefile,v 1.6 2015/02/16 10:15:45 jperkin Exp $

PKGNAME=	suse_expat-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	libexpat1-2.0.1-109.7.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for expat

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
