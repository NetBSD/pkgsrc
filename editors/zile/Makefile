# $NetBSD: Makefile,v 1.9 2003/08/09 10:48:10 seb Exp $

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

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
