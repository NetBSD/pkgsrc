# $NetBSD: Makefile,v 1.2 2005/03/02 23:32:12 minskim Exp $
#

DISTNAME=		gtmess-0.9
CATEGORIES=		chat
MASTER_SITES=		http://www.geocities.com/montajoe/gtmess/

MAINTAINER=		luapzz@gmail.com
HOMEPAGE=		http://www.geocities.com/montajoe/gtmess/
COMMENT=		Console-based MSN Messenger client

DEPENDS+=		tk-[0-9]*:../../x11/tk

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		ac_cv_search_iconv=${BUILDLINK_LDADD.iconv:Q}

INCOMPAT_CURSES=	NetBSD-1.*

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
