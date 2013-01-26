# $NetBSD: Makefile,v 1.19 2013/01/26 10:55:43 obache Exp $

DISTNAME=	gettext-2.3.7
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Ruby localization library like as GNU gettext
LICENSE=	ruby-license OR gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-levenshtein-[0-9]*:../../textproc/ruby-levenshtein

OVERRIDE_GEMSPEC=	:files po/de/gettext.po.bak= po/gettext.pot~=

pre-configure:
	cd ${WRKSRC}; ${FIND} . -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
