# $NetBSD: Makefile,v 1.1.1.1 2004/02/29 03:31:14 xtraeme Exp $
#

DISTNAME=	iftop-0.16
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~pdw/iftop/download/
COMMENT=	Display bandwidth usage on an interface

USE_BUILDLINK3=		yes
USE_NCURSES=		# mvchgat()
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
