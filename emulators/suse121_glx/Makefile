# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:36:48 obache Exp $

DISTNAME=	suse_glx-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	Mesa-7.11-11.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	x11

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
