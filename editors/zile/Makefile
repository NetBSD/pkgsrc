# $NetBSD: Makefile,v 1.4 2003/06/02 01:20:01 jschauma Exp $

DISTNAME=		zile-1.6.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://zile.sourceforge.net
COMMENT=		Emacs-like text editor

GNU_CONFIGURE=		yes
USE_NCURSES=		# KEY_RESIZE (also uses stdscr->_delay directly)
USE_BUILDLINK2= 	yes
INFO_FILES=		zile.info

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
