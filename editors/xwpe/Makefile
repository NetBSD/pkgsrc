# $NetBSD: Makefile,v 1.1.1.1 2004/07/06 07:58:48 xtraeme Exp $
#

DISTNAME=	xwpe-1.5.29a
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
