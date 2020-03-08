# $NetBSD: Makefile,v 1.21 2020/03/08 13:48:34 taca Exp $

DISTNAME=	gettext_i18n_rails-1.8.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grosser/gettext_i18n_rails
COMMENT=	Simple FastGettext Rails integration
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-fast_gettext>=0.9.0:../../devel/ruby-fast_gettext

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
