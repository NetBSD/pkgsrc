# $NetBSD: Makefile,v 1.54 2022/09/09 13:17:47 taca Exp $

DISTNAME=	sqlite3-1.5.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/luislavena/sqlite3-ruby
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

USE_GCC_RUNTIME=	yes
RUBY_EXTCONF_ARGS=	--enable-system-libraries
OVERRIDE_GEMSPEC+=	:files ports/archives/sqlite-autoconf-3380500.tar.gz=

pre-configure:
	${RM} -f ${WRKSRC}/ports/archives/sqlite-autoconf-3380500.tar.gz

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
