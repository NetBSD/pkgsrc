# $NetBSD: Makefile,v 1.2 2010/02/21 13:07:19 wiz Exp $

DISTNAME=		mysql-5.1.44
PKGNAME=		${DISTNAME:S/-/-embedded-/}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_MYSQL:=MySQL-5.1/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		MySQL 5, a free SQL database (embedded server)
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/mysqld
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-embedded-server
CONFIGURE_ARGS+=	--with-mysqld-ldflags=-all-static
CONFIGURE_ARGS+=	--with-pic
CONFIGURE_ARGS+=	--without-bench
CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-libedit
CONFIGURE_ARGS+=	--without-libwrap
CONFIGURE_ARGS+=	--without-man
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--without-ssl

# the usual == problem
CHECK_PORTABILITY_SKIP=	configure BUILD/compile-pentium-gcov configure~

CFLAGS+=		-fPIC -DPIC
CXXFLAGS+=		-fPIC -DPIC

INSTALLATION_DIRS=	mysqld/lib/mysql

# install headers and client library
INSTALL_DIRS=	include libmysql sql

# We only need readline to placate the configure script.  None of the
# binaries are actually linked against -lreadline, so make this only
# a build-time dependency.
#
BUILDLINK_DEPMETHOD.readline=	build
# NetBSD version is not recognized
USE_BUILTIN.readline=		no
.include "../../devel/readline/buildlink3.mk"

post-install:
	${INSTALL_LIB} ${WRKSRC}/libmysqld/libmysqld.a \
		${DESTDIR}${PREFIX}/mysqld/lib/mysql

.include "../../mk/bsd.pkg.mk"
