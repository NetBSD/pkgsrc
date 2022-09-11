# $NetBSD: Makefile,v 1.55 2022/09/11 16:04:27 taca Exp $

DISTNAME=	sqlite3-1.5.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/luislavena/sqlite3-ruby
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile2>=2.8.0<2.9:../../misc/ruby-mini_portile2

USE_GCC_RUNTIME=	yes
RUBY_EXTCONF_ARGS=	--enable-system-libraries
OVERRIDE_GEMSPEC+=	:files ports/archives/sqlite-autoconf-3380500.tar.gz=

pre-configure:
	${RM} -f ${WRKSRC}/ports/archives/sqlite-autoconf-3380500.tar.gz

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
