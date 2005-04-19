# $NetBSD: Makefile,v 1.15 2005/04/19 00:49:49 wiz Exp $
#

DISTNAME=	grhino-0.15.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rhino/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rhino.sourceforge.net/
COMMENT=	Othello (Reversi) engine

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
