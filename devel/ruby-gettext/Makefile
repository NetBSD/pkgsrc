# $NetBSD: Makefile,v 1.22 2014/03/11 10:00:21 obache Exp $

DISTNAME=	gettext-3.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-lgpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-text-[0-9]*:../../textproc/ruby-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
