# $NetBSD: Makefile,v 1.8 2006/02/17 19:22:30 wiz Exp $
#

DISTNAME=	xwpe-1.5.29a
PKGREVISION=	3
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
