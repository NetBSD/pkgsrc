# $NetBSD: Makefile,v 1.1.1.1 2005/02/22 14:33:05 minskim Exp $
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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
