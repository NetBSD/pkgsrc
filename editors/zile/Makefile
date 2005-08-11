# $NetBSD: Makefile,v 1.17 2005/08/11 15:33:08 adam Exp $

DISTNAME=	zile-2.2.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://zile.sourceforge.net/
COMMENT=	Emacs-like text editor

USE_MAKEINFO=	yes
USE_NCURSES=	yes	# uses stdscr->_delay directly
GNU_CONFIGURE=	yes

INFO_FILES=	zile.info

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
