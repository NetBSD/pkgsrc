# $NetBSD: Makefile,v 1.13 2017/06/21 15:42:10 taca Exp $

DISTNAME=	activeldap-3.2.2
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://activeldap.github.io/
COMMENT=	Object oriented interface to LDAP
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-locale>=0:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-gettext_i18n_rails>=0:../../devel/ruby-gettext_i18n_rails
# gettext_i18n_rails depends on fast_gettext
#DEPENDS+=	${RUBY_PKGPREFIX}-fast_gettext>=0:../../devel/ruby-fast_gettext

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
