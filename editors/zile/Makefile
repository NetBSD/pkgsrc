# $NetBSD: Makefile,v 1.23 2008/07/14 12:56:03 joerg Exp $

DISTNAME=	zile-2.2.50
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zile.sourceforge.net/
COMMENT=	Emacs-like text editor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	makeinfo
USE_NCURSES=	yes	# uses stdscr->_delay directly
GNU_CONFIGURE=	yes

INFO_FILES=	# PLIST

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
