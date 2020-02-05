# $NetBSD: Makefile,v 1.38 2020/02/05 14:53:36 taca Exp $

DISTNAME=	gettext-3.3.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ruby-gettext.github.com/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license OR gnu-lgpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-text>=1.3.0:../../textproc/ruby-text

USE_LANGUAGES=		# none
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
