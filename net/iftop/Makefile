# $NetBSD: Makefile,v 1.12 2012/10/23 17:18:28 asau Exp $
#

DISTNAME=	iftop-0.17
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~pdw/iftop/download/
COMMENT=	Display bandwidth usage on an interface

USE_NCURSES=		chgat
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
