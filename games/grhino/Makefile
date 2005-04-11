# $NetBSD: Makefile,v 1.14 2005/04/11 21:45:50 tv Exp $
#

DISTNAME=	grhino-0.12.0
PKGREVISION=	1
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
