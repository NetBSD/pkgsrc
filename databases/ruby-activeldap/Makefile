# $NetBSD: Makefile,v 1.1.1.1 2008/06/23 01:36:56 taca Exp $

DISTNAME=	activeldap-1.0.1
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
