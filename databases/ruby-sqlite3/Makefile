# $NetBSD: Makefile,v 1.96.2.1 2026/06/09 22:49:43 maya Exp $

DISTNAME=	sqlite3-2.9.5
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/luislavena/sqlite3-ruby
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile2>=2.8.0<2.9:../../misc/ruby-mini_portile2

USE_GCC_RUNTIME=	yes
RUBY_EXTCONF_ARGS=	--enable-system-libraries
OVERRIDE_GEMSPEC+=	:files ${BUNDLED_ARCHIVE}=

BUNDLED_ARCHIVE=	ports/archives/sqlite-autoconf-3530200.tar.gz

pre-configure:
	${RM} -f ${WRKSRC}/${BUNDLED_ARCHIVE}

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
