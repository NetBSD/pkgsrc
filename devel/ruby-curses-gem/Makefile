# $NetBSD: Makefile,v 1.2 2015/02/02 12:24:23 taca Exp $

DISTNAME=	curses-1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/curses
COMMENT=	Ruby binding for curses, ncurses, and PDCurses
LICENSE=	2-clause-bsd

RUBY_VERSION_SUPPORTED= 21 # 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
