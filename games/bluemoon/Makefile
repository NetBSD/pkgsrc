# $NetBSD: Makefile,v 1.3 2008/09/08 19:13:42 wiz Exp $
#

DISTNAME=	bluemoon-1.3.2
CATEGORIES=	games
MASTER_SITES=	http://keldon.net/bluemoon/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://keldon.net/bluemoon/
COMMENT=	Blue Moon game with AI

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
