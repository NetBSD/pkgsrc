# $NetBSD: Makefile,v 1.13 2013/02/06 19:30:57 jperkin Exp $
#

DISTNAME=	iftop-0.17
PKGREVISION=	2
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
