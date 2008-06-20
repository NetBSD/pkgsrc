# $NetBSD: Makefile,v 1.20 2008/06/20 01:09:32 joerg Exp $
#

DISTNAME=	tn5250-0.12.51
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blarg.net/users/mmadore/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linux-sna.org/software/5250/
COMMENT=	Implementation of the IBM 5250 telnet protocol

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
