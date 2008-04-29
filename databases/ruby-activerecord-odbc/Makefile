# $NetBSD: Makefile,v 1.2 2008/04/29 16:56:18 jlam Exp $

DISTNAME=	activerecord-odbc-adapter-2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-adapter//}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odbc-rails.rubyforge.org/
COMMENT=	ActiveRecord ODBC adapter

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.0.2:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-odbc>=0.9991:../../databases/ruby-odbc

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
