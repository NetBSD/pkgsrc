# $NetBSD: Makefile,v 1.9 2004/11/12 06:39:20 jlam Exp $
#

DISTNAME=		physfs-1.0.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.icculus.org/physfs/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.icculus.org/physfs/
COMMENT=		Library providing abstract access to various archives

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
