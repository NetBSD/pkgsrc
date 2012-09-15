# $NetBSD: Makefile,v 1.2 2012/09/15 15:03:23 obache Exp $
#

DISTNAME=	mysql2-0.3.11
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://github.com/brianmario/mysql2/
COMMENT=	Simple, fast Mysql library for Ruby, binding to libmysql
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/gem.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
