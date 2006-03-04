# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:19 jlam Exp $
#

DISTNAME=	giFTcurs-0.6.2
PKGNAME=	${DISTNAME:S/FT/ft/}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/giftcurs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/giftcurs/
COMMENT=	Curses frontend to the giFT daemon

BUILD_USES_MSGFMT=	yes

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
