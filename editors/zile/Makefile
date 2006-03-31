# $NetBSD: Makefile,v 1.21 2006/03/31 15:40:37 jlam Exp $

DISTNAME=	zile-2.2.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zile.sourceforge.net/
COMMENT=	Emacs-like text editor

USE_TOOLS+=	makeinfo
USE_NCURSES=	yes	# uses stdscr->_delay directly
GNU_CONFIGURE=	yes

INFO_FILES=	# PLIST

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
