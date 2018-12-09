# $NetBSD: Makefile,v 1.21 2018/12/09 21:05:33 adam Exp $
#

DISTNAME=	iftop-1.0pre4
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~pdw/iftop/download/
COMMENT=	Display bandwidth usage on an interface

USE_CURSES=		chgat
FAKE_NCURSES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-resolver=netdb_1thread

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
