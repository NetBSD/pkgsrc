# $NetBSD: Makefile,v 1.21 2021/12/08 16:05:57 adam Exp $
#

DISTNAME=	giFTcurs-0.6.2
PKGNAME=	${DISTNAME:S/FT/ft/}
PKGREVISION=	12
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/giftcurs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/giftcurs/
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
