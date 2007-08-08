# $NetBSD: Makefile,v 1.10 2007/08/08 17:33:44 joerg Exp $
#

DISTNAME=	iftop-0.17
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~pdw/iftop/download/
COMMENT=	Display bandwidth usage on an interface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_NCURSES=		YES # mvchgat()
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
