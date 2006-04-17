# $NetBSD: Makefile,v 1.24 2006/04/17 13:46:28 wiz Exp $
#

DISTNAME=	grhino-0.15.0
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rhino/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rhino.sourceforge.net/
COMMENT=	Othello (Reversi) engine

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
