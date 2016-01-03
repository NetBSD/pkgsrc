# $NetBSD: Makefile,v 1.29 2016/01/03 05:36:05 taca Exp $

DISTNAME=	gettext-3.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license OR gnu-lgpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-text>=1.3.0:../../textproc/ruby-text

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
