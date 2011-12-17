# $NetBSD: Makefile,v 1.2 2011/12/17 17:59:52 taca Exp $

DISTNAME=	acts_as_versioned-0.2.3
PKGREVISION=	2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ar-versioned.rubyforge.org/
COMMENT=	Simple versioning for ActiveRecord
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_SUPPORTED=	2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
