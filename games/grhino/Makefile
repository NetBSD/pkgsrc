# $NetBSD: Makefile,v 1.91 2021/04/21 11:41:40 adam Exp $
#

DISTNAME=		grhino-0.16.1
PKGREVISION=		29
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rhino/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rhino.sourceforge.net/
COMMENT=		Othello (Reversi) engine

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
