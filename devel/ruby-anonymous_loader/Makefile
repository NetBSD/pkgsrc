# $NetBSD: Makefile,v 1.2 2026/11/02 06:57:37 taca Exp $

DISTNAME=	anonymous_loader-0.1.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-oauth/anonymous_loader
COMMENT=	Load Ruby source files inside anonymous namespaces
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.17<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
