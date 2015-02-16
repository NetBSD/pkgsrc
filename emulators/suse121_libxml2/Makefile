# $NetBSD: Makefile,v 1.10 2015/02/16 10:15:46 jperkin Exp $

PKGNAME=	suse_libxml2-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
RPMUPDPKGS+=	libxml2-2.7.8+git20110708-3.24.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libxml2

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
