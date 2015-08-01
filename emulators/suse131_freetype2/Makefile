# $NetBSD: Makefile,v 1.4.4.1 2015/08/01 09:19:54 tron Exp $

PKGNAME=	suse_freetype2-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libfreetype6-2.5.0.1-2.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for freetype-2.x

EMUL_MODULES.linux=	base png

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
