# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:15:35 jlam Exp $

DISTNAME=	acts_as_versioned-0.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	database

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ar-versioned.rubyforge.org/
COMMENT=	Simple versioning for ActiveRecord

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=1.10.1:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.1.1:../../devel/ruby-activesupport

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
