# $NetBSD: Makefile,v 1.21 2014/03/31 08:29:44 wiz Exp $

DISTNAME=		physfs-2.0.3
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--disable-cdrom
.endif

.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
