# $NetBSD: Makefile,v 1.5 2005/05/22 20:07:57 jlam Exp $
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
USE_X11=		yes

BUILD_TARGET=		# defined

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
