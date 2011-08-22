# $NetBSD: Makefile,v 1.4 2011/08/22 14:57:08 chs Exp $

DISTNAME=	suse_libpng-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
DISTFILES=	libpng14-14-1.4.3-3.3.1.${SUSE_ARCH}.rpm \
		libpng12-0-1.2.46-7.3.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
