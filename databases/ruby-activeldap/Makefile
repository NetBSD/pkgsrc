# $NetBSD: Makefile,v 1.4 2010/09/10 04:09:42 taca Exp $

DISTNAME=	activeldap-1.2.2
CATEGORIES=	databases

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-activeldap/
COMMENT=	Object oriented interface to LDAP
LICENSE=	ruby-license OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.3.5:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.0.5:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=2.1.0:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-gettext-activerecord>=2.1.0:../../devel/ruby-gettext-activerecord

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
