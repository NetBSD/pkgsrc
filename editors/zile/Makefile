# $NetBSD: Makefile,v 1.10 2003/09/27 17:07:36 grant Exp $

DISTNAME=		zile-1.6.2
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://zile.sourceforge.net
COMMENT=		Emacs-like text editor

GNU_CONFIGURE=		yes
USE_NCURSES=		# KEY_RESIZE (also uses stdscr->_delay directly)
USE_BUILDLINK2= 	yes
USE_MAKEINFO=		YES
INFO_FILES=		zile.info

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
