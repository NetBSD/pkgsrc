# $NetBSD: Makefile,v 1.20 2013/07/15 02:02:21 ryoon Exp $
#

DISTNAME=		physfs-1.0.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://offload1.icculus.org/physfs/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.icculus.org/physfs/
COMMENT=		Library providing abstract access to various archives

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-pthreads
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
