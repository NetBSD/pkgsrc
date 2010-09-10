# $NetBSD: Makefile,v 1.2 2010/09/10 05:52:09 taca Exp $

DISTNAME=	locale_rails-2.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-locale-rails.html
COMMENT=	Rails localized functions using ruby-locale
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
