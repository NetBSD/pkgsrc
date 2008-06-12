# $NetBSD: Makefile,v 1.16 2008/06/12 02:14:28 joerg Exp $
#

DISTNAME=		physfs-1.0.1
CATEGORIES=		devel
MASTER_SITES=		http://offload1.icculus.org/physfs/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.icculus.org/physfs/
COMMENT=		Library providing abstract access to various archives

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-pthreads
PTHREAD_AUTO_VARS=	yes

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
