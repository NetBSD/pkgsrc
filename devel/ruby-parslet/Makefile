# $NetBSD: Makefile,v 1.9 2020/03/08 14:45:06 taca Exp $

DISTNAME=	parslet-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kschiess.github.com/parslet/
COMMENT=	Parser construction library with great error reporting
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-blankslate>=2.0:../../devel/ruby-blankslate

OVERRIDE_GEMSPEC+=	blankslate>=2.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
