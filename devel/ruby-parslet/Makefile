# $NetBSD: Makefile,v 1.10 2026/02/06 08:35:12 wiz Exp $

DISTNAME=	parslet-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kschiess/parslet/
COMMENT=	Parser construction library with great error reporting
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-blankslate>=2.0:../../devel/ruby-blankslate

OVERRIDE_GEMSPEC+=	blankslate>=2.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
