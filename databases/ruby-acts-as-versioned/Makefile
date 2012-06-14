# $NetBSD: Makefile,v 1.6 2012/06/14 15:14:09 taca Exp $

DISTNAME=	acts_as_versioned-0.6.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ar-versioned.rubyforge.org/
COMMENT=	Simple versioning for ActiveRecord
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

RUBY_RAILS_SUPPORTED=	3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
