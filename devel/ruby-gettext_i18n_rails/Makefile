# $NetBSD: Makefile,v 1.23 2023/06/06 13:36:44 taca Exp $

DISTNAME=	gettext_i18n_rails-1.11.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grosser/gettext_i18n_rails
COMMENT=	Simple FastGettext Rails integration
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-fast_gettext>=0.9.0:../../devel/ruby-fast_gettext

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
