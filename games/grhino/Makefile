# $NetBSD: Makefile,v 1.52 2012/09/07 19:16:36 adam Exp $
#

DISTNAME=		grhino-0.16.0
PKGREVISION=		15
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rhino/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rhino.sourceforge.net/
COMMENT=		Othello (Reversi) engine

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
