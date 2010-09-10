# $NetBSD: Makefile,v 1.2 2010/09/10 06:29:40 taca Exp $

DISTNAME=	termcolor-1.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/jugyo/termcolor
COMMENT=	ANSI color formatting like HTML for output in terminal
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
