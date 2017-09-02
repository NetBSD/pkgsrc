# $NetBSD: Makefile,v 1.3 2017/09/02 15:22:29 taca Exp $

DISTNAME=	gettext-setup-0.28
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/gettext-setup-gem
COMMENT=	Ease internationalization with fast_gettext
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-fast_gettext>=1.1.0:../../devel/ruby-fast_gettext
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=3.0.2:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-locale>=0:../../devel/ruby-locale

OVERRIDE_GEMSPEC+=	fast_gettext>=1.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
