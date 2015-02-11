# $NetBSD: Makefile,v 1.9 2015/02/11 09:38:13 obache Exp $

DISTNAME=	suse_libtiff-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
DISTFILES=	libtiff-3.7.3-2.6.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
