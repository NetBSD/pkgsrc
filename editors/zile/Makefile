# $NetBSD: Makefile,v 1.6 2003/06/30 02:42:15 seb Exp $

DISTNAME=		zile-1.6.2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://zile.sourceforge.net
COMMENT=		Emacs-like text editor

GNU_CONFIGURE=		yes
USE_NCURSES=		# KEY_RESIZE (also uses stdscr->_delay directly)
USE_BUILDLINK2= 	yes
USE_NEW_TEXINFO=	YES
USE_MAKEINFO=		YES
INFO_FILES=		zile.info

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
