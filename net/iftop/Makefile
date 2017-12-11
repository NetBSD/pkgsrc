# $NetBSD: Makefile,v 1.20 2017/12/11 10:44:16 manu Exp $
#

DISTNAME=	iftop-1.0pre4
#PKGREVISION=	1
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
