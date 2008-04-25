# $NetBSD: Makefile,v 1.1.1.1 2008/04/25 22:48:59 wiz Exp $
#

DISTNAME=	bluemoon-1.1.2
CATEGORIES=	games
MASTER_SITES=	http://keldon.net/bluemoon/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://keldon.net/bluemoon/
COMMENT=	Blue Moon game with AI

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
