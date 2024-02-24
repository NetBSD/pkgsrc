# $NetBSD: Makefile,v 1.28 2024/02/24 07:08:14 taca Exp $

DISTNAME=	activeldap-7.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/activeldap-/activeldap${RUBY_RAILS}-/}
CATEGORIES=	databases

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://activeldap.github.io/
COMMENT=	Object oriented interface to LDAP
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-locale>=0:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=0:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-gettext_i18n_rails>=0:../../devel/ruby-gettext_i18n_rails
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=0:../../textproc/ruby-builder

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
