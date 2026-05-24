# $NetBSD: Makefile,v 1.26 2026/05/24 14:14:48 taca Exp $

DISTNAME=	gettext_i18n_rails-2.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grosser/gettext_i18n_rails
COMMENT=	Simple FastGettext Rails integration
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-fast_gettext>=0.9.0:../../devel/ruby-fast_gettext

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
