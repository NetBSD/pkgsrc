# $NetBSD: Makefile,v 1.4 2017/09/04 18:00:53 wiz Exp $

DISTNAME=	locale_rails-2.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-locale-rails.html
COMMENT=	Rails localized functions using ruby-locale
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
