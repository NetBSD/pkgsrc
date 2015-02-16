# $NetBSD: Makefile,v 1.11 2015/02/16 10:15:43 jperkin Exp $

PKGNAME=	suse_freetype2-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
DISTFILES=	freetype2-2.1.10-4.9.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for freetype-2.x

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
