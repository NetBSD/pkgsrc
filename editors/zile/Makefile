# $NetBSD: Makefile,v 1.24 2009/07/19 11:49:10 zafer Exp $

DISTNAME=	zile-2.3.9
CATEGORIES=	editors
MASTER_SITES=	http://ftp.gnu.org/gnu/zile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/zile/
COMMENT=	Emacs-like text editor
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	makeinfo
USE_NCURSES=	yes	# uses stdscr->_delay directly
GNU_CONFIGURE=	yes

INFO_FILES=	# PLIST

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
