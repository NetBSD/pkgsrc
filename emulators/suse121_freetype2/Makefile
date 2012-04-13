# $NetBSD: Makefile,v 1.2 2012/04/13 11:56:33 obache Exp $

DISTNAME=	suse_freetype2-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libfreetype6-2.4.7-6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for freetype-2.x

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
