# $NetBSD: Makefile,v 1.8 2015/02/16 10:15:43 jperkin Exp $

PKGNAME=	suse_libjpeg-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
DISTFILES=	libjpeg-6.2.0-739.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for JPEG

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
