# $NetBSD: Makefile,v 1.1 2013/02/11 08:47:19 taca Exp $

DISTNAME=	parslet-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kschiess.github.com/parslet/
COMMENT=	Parser construction library with great error reporting
LICENSE=        mit

DEPENDS+=	${RUBY_PKGPREFIX}-blankslate>=2.0:../../devel/ruby-blankslate

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
