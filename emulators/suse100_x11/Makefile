# $NetBSD: Makefile,v 1.7 2008/09/03 09:42:45 obache Exp $

DISTNAME=	suse_x11-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
DISTFILES=	xorg-x11-libs-6.8.2-100.13.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for X11

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
