# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:16 obache Exp $

DISTNAME=	suse_libpng-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libpng12-0-1.2.50-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libpng16-16-1.6.6-1.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
