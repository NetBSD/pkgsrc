# $NetBSD: Makefile,v 1.6 2007/07/29 05:18:42 jlam Exp $

DISTNAME=	suse_fontconfig-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES=	fontconfig-2.3.2.20050721-10.2.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for fontconfig

EMUL_MODULES.linux=	expat freetype2

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
