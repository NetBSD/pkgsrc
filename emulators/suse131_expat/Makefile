# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:15 obache Exp $

DISTNAME=	suse_expat-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libexpat1-2.1.0-12.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for expat

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
