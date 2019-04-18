# $NetBSD: Makefile,v 1.25 2019/04/18 07:38:53 adam Exp $

DISTNAME=	physfs-3.0.2
CATEGORIES=	devel
MASTER_SITES=	http://offload1.icculus.org/physfs/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icculus.org/physfs/
COMMENT=	Library providing abstract access to various archives
LICENSE=	zlib

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PTHREAD_AUTO_VARS=	yes
PKGCONFIG_OVERRIDE+=	extras/physfs.pc.in

CFLAGS.SunOS+=		-DPHYSFS_NO_CDROM_SUPPORT=1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
