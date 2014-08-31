# $NetBSD: Makefile,v 1.24 2014/08/31 08:09:50 obache Exp $

DISTNAME=	gettext-3.1.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license OR gnu-lgpl-v3

RUBY_VERSION_SUPPORTED=	193 200 21

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-text-[0-9]*:../../textproc/ruby-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
