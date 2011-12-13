# $NetBSD: Makefile,v 1.5 2011/12/13 15:52:18 taca Exp $

DISTNAME=	gettext_rails-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-gettext.html
COMMENT=	Localization for Ruby on Rails using Ruby-GetText-Package
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale-rails>=2.0.5:../../devel/ruby-locale-rails
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_RAILS_DEPENDS}

RUBY_RAILS_SUPPORTED=	# defined

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
