# $NetBSD: Makefile,v 1.2.4.1 2011/02/27 00:26:14 tron Exp $

DISTNAME=	sqlite-ruby-2.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
