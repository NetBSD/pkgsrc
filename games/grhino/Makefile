# $NetBSD: Makefile,v 1.28 2006/09/16 12:20:37 jmmv Exp $
#

DISTNAME=		grhino-0.15.1
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rhino/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rhino.sourceforge.net/
COMMENT=		Othello (Reversi) engine

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
