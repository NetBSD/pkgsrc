# $NetBSD: Makefile,v 1.18 2017/01/04 19:36:11 roy Exp $
#

DISTNAME=	giFTcurs-0.6.2
PKGNAME=	${DISTNAME:S/FT/ft/}
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/giftcurs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/giftcurs/
COMMENT=	Curses frontend to the giFT daemon

USE_TOOLS+=		msgfmt pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
