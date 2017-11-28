# $NetBSD: Makefile,v 1.24 2017/11/28 14:47:31 wiz Exp $

DISTNAME=		physfs-3.0.1
CATEGORIES=		devel
MASTER_SITES=		http://offload1.icculus.org/physfs/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.icculus.org/physfs/
COMMENT=		Library providing abstract access to various archives
LICENSE=		zlib

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PTHREAD_AUTO_VARS=	yes

PKGCONFIG_OVERRIDE+=	extras/physfs.pc.in

CFLAGS.SunOS+=		-DPHYSFS_NO_CDROM_SUPPORT=1

.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
