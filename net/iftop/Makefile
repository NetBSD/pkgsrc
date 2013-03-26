# $NetBSD: Makefile,v 1.15 2013/03/26 20:23:43 bsiegert Exp $
#

DISTNAME=	iftop-0.17
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~pdw/iftop/download/
COMMENT=	Display bandwidth usage on an interface

USE_NCURSES=		chgat
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-resolver=netdb_1thread

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
