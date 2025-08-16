# $NetBSD: Makefile,v 1.27 2025/08/16 10:29:37 prlw1 Exp $

DISTNAME=	physfs-3.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=icculus/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.icculus.org/physfs/
COMMENT=	Library providing abstract access to various archives
LICENSE=	zlib

USE_LANGUAGES=		c c++
PTHREAD_AUTO_VARS=	yes
PKGCONFIG_OVERRIDE+=	extras/physfs.pc.in

CFLAGS.SunOS+=		-DPHYSFS_NO_CDROM_SUPPORT=1

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
