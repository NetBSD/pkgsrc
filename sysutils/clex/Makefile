# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:46 joerg Exp $
#

DISTNAME=		clex-3.16
CATEGORIES=		sysutils
MASTER_SITES=		http://www.clex.sk/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.clex.sk/download/
COMMENT=		File manager with a full-screen user interface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_NCURSES=		# enter_{bold,reverse,underline}_mode
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
