# $NetBSD: Makefile,v 1.21 2013/09/15 09:59:08 taca Exp $

DISTNAME=	gettext-3.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-lgpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-text-[0-9]*:../../textproc/ruby-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
