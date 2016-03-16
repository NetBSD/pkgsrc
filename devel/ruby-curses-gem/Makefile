# $NetBSD: Makefile,v 1.5 2016/03/16 13:07:31 taca Exp $

DISTNAME=	curses-1.0.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/curses
COMMENT=	Ruby binding for curses, ncurses, and PDCurses
LICENSE=	2-clause-bsd

RUBY_VERSION_SUPPORTED= 21 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
