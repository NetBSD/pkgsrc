# $NetBSD: Makefile,v 1.1.1.1 2009/12/07 11:23:57 fhajny Exp $

DISTNAME=	locale_rails-2.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-locale-rails.html
COMMENT=	Rails localized functions using ruby-locale
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale

GEM_BUILD=	gemspec

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
