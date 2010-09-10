# $NetBSD: Makefile,v 1.2 2010/09/10 05:45:34 taca Exp $

DISTNAME=	gettext_rails-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-gettext.html
COMMENT=	Localization for Ruby on Rails using Ruby-GetText-Package
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale-rails>=2.0.5:../../devel/ruby-locale-rails
DEPENDS+=	${RUBY_PKGPREFIX}-gettext-activerecord>=2.1.0:../../devel/ruby-gettext-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-rails>=2.3.2:../../www/rails

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
