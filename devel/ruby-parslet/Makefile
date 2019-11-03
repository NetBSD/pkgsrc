# $NetBSD: Makefile,v 1.7 2019/11/03 10:00:24 rillig Exp $

DISTNAME=	parslet-1.8.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kschiess.github.com/parslet/
COMMENT=	Parser construction library with great error reporting
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-blankslate>=2.0:../../devel/ruby-blankslate

OVERRIDE_GEMSPEC+=	blankslate>=2.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
