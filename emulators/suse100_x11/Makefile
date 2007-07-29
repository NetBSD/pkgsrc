# $NetBSD: Makefile,v 1.6 2007/07/29 05:19:01 jlam Exp $

DISTNAME=	suse_x11-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES=	xorg-x11-libs-6.8.2-100.2.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for X11

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
