# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:18 wiz Exp $

DISTNAME=	termcolor-1.2.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jugyo/termcolor
COMMENT=	ANSI color formatting like HTML for output in terminal
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
