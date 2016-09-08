# $NetBSD: Makefile,v 1.6 2016/09/08 15:19:16 joerg Exp $

DISTNAME=	curses-1.0.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/curses
COMMENT=	Ruby binding for curses, ncurses, and PDCurses
LICENSE=	2-clause-bsd

RUBY_VERSIONS_ACCEPTED= 21 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
