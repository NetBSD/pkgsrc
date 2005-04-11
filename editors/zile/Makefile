# $NetBSD: Makefile,v 1.16 2005/04/11 21:45:42 tv Exp $

DISTNAME=		zile-1.6.2
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://zile.sourceforge.net/
COMMENT=		Emacs-like text editor

GNU_CONFIGURE=		yes
USE_NCURSES=		# uses stdscr->_delay directly
USE_MAKEINFO=		YES
INFO_FILES=		zile.info

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
