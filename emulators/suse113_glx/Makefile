# $NetBSD: Makefile,v 1.2 2011/02/10 02:55:46 chs Exp $

DISTNAME=	suse_glx-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES+=	Mesa-7.8.2-1.3.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	x11

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
