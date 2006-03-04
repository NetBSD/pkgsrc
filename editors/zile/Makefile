# $NetBSD: Makefile,v 1.19 2006/03/04 21:29:34 jlam Exp $

DISTNAME=	zile-2.2.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zile.sourceforge.net/
COMMENT=	Emacs-like text editor

USE_MAKEINFO=	yes
USE_NCURSES=	yes	# uses stdscr->_delay directly
GNU_CONFIGURE=	yes

INFO_FILES=	zile.info

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
