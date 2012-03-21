# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:36:14 obache Exp $

DISTNAME=	suse_expat-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libexpat1-2.0.1-109.1.4.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for expat

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
