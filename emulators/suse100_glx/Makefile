# $NetBSD: Makefile,v 1.8 2015/02/11 09:38:13 obache Exp $

DISTNAME=	suse_glx-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	x11

# This symlink is managed by ldconfig(8).
CHECK_FILES_SKIP+=	${EMULDIR}/usr/${LINUX_LIBSUBDIR}/libglide.so.3

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
