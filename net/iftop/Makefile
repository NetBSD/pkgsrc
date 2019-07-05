# $NetBSD: Makefile,v 1.22 2019/07/05 19:16:19 adam Exp $

DISTNAME=	iftop-1.0pre4
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/pdw/iftop/
COMMENT=	Display bandwidth usage on an interface
LICENSE=	gnu-gpl-v2

USE_CURSES=		chgat
FAKE_NCURSES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-resolver=netdb_1thread

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
