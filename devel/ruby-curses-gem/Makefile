# $NetBSD: Makefile,v 1.4 2015/12/30 15:49:10 taca Exp $

DISTNAME=	curses-1.0.1
PKGREVISION=	1
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
