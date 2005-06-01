# $NetBSD: Makefile,v 1.6 2005/06/01 18:02:46 jlam Exp $
#

DISTNAME=	xwpe-1.5.29a
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_NCURSES=		# tigetstr()

BUILD_TARGET=		# defined

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
