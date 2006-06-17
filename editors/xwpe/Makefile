# $NetBSD: Makefile,v 1.10 2006/06/17 17:56:10 rillig Exp $
#

DISTNAME=	xwpe-1.5.29a
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_NCURSES=		yes # tigetstr()

BUILD_TARGET=		# the one from the Makefile

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
