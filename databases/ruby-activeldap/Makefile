# $NetBSD: Makefile,v 1.2 2010/02/14 12:45:27 taca Exp $

DISTNAME=	activeldap-1.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-activeldap/
COMMENT=	Object oriented interface to LDAP

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=1.90.0:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.0.0:../../databases/ruby-activerecord
DEPENDS+=	hoe>=1.5.0:../../devel/hoe

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
