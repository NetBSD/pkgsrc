# $NetBSD: Makefile,v 1.6 2023/01/30 13:40:06 taca Exp $

DISTNAME=	sqlite-ruby-2.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
