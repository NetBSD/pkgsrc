# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=	xwpe-1.5.29a
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_NCURSES=		# tigetstr()
USE_X11=		yes

ALL_TARGET=		# defined

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
