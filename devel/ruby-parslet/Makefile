# $NetBSD: Makefile,v 1.4 2015/11/23 07:19:24 taca Exp $

DISTNAME=	parslet-1.7.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kschiess.github.com/parslet/
COMMENT=	Parser construction library with great error reporting
LICENSE=        mit

DEPENDS+=	${RUBY_PKGPREFIX}-blankslate>=2.0:../../devel/ruby-blankslate

OVERRIDE_GEMSPEC+=	blankslate>=2.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
