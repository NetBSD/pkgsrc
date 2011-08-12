# $NetBSD: Makefile,v 1.5 2011/08/12 16:42:35 taca Exp $

DISTNAME=	activerecord-odbc-adapter-2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-adapter//}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odbc-rails.rubyforge.org/
COMMENT=	ActiveRecord ODBC adapter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-odbc>=0.9991:../../databases/ruby-odbc
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

RUBY_RAILS=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
