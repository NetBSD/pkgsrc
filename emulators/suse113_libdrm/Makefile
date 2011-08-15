# $NetBSD: Makefile,v 1.1.1.1 2011/08/15 09:07:04 wiz Exp $

DISTNAME=	suse_libdrm-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES+=	libdrm-2.4.21-1.2.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for libdrm

EMUL_MODULES.linux=	x11

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
