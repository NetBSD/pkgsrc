# $NetBSD: Makefile,v 1.3 2010/02/16 03:15:11 taca Exp $

DISTNAME=	activeldap-1.2.1
PKGREVISION=	1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
DIST_SUBDIR=	${DISTNAME}-20091216

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-activeldap/
COMMENT=	Object oriented interface to LDAP

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.3.5:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-gettext-activerecord>=2.1.0:../../devel/ruby-gettext-activerecord

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
