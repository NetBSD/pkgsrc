# $NetBSD: Makefile,v 1.18.2.1 2017/04/25 18:01:45 bsiegert Exp $
#

DISTNAME=	iftop-0.17
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~pdw/iftop/download/
COMMENT=	Display bandwidth usage on an interface

USE_CURSES=		chgat
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-resolver=netdb_1thread

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
