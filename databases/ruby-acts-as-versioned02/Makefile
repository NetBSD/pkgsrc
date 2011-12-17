# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:55:54 taca Exp $

DISTNAME=	acts_as_versioned-0.2.3
PKGREVISION=	1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ar-versioned.rubyforge.org/
COMMENT=	Simple versioning for ActiveRecord
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=1.10.1<3.0.0:../../databases/ruby-activerecord

# Note: acts_as_versioned-0.6.0 supports only rails3.

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
