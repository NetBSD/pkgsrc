# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:42 obache Exp $

PKGNAME=	suse_expat-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libexpat1-2.1.0-12.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for expat

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
