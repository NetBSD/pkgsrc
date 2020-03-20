# $NetBSD: Makefile,v 1.13 2020/03/20 15:08:08 taca Exp $

DISTNAME=	gettext_activerecord-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-gettext.html
COMMENT=	Localization for ActiveRecord using Ruby-GetText-Package
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=2.1.0:../../devel/ruby-gettext
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	24
RUBY_RAILS_ACCEPTED=	# defined

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

pre-build:
	${FIND} ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
