# $NetBSD: Makefile,v 1.20 2020/03/23 15:23:55 taca Exp $

DISTNAME=	activeldap-5.2.4
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

RUBY_VERSIONS_INCOMPATIBLE=	24
RUBY_RAILS_ACCEPTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
