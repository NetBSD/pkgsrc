# $NetBSD: Makefile,v 1.1 2026/07/18 14:58:27 taca Exp $

DISTNAME=	anonymous_loader-0.1.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-oauth/anonymous_loader
COMMENT=	Load Ruby source files inside anonymous namespaces
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.14<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
