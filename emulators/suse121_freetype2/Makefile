# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:36:34 obache Exp $

DISTNAME=	suse_freetype2-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	libfreetype6-2.4.7-3.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for freetype-2.x

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
