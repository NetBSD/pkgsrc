# $NetBSD: Makefile,v 1.11 2004/11/28 14:35:19 wiz Exp $
#

DISTNAME=		physfs-1.0.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://www.icculus.org/physfs/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.icculus.org/physfs/
COMMENT=		Library providing abstract access to various archives

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-pthreads

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
