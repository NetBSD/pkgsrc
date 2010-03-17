# $NetBSD: Makefile,v 1.4 2010/03/17 14:17:49 joerg Exp $
#

DISTNAME=		clex-3.16
CATEGORIES=		sysutils
MASTER_SITES=		http://www.clex.sk/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.clex.sk/download/
COMMENT=		File manager with a full-screen user interface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_NCURSES=		yes # enter_{bold,reverse,underline}_mode
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
