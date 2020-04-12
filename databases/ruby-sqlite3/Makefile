# $NetBSD: Makefile,v 1.47 2020/04/12 08:28:27 adam Exp $

DISTNAME=	sqlite3-1.4.2
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/luislavena/sqlite3-ruby
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
