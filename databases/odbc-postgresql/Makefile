# $NetBSD: Makefile,v 1.7 2002/04/03 09:29:55 jlam Exp $

DISTNAME=		postgresql-${DIST_VERS}
PKGNAME=		odbc-postgresql-${BASE_VERS}
CATEGORIES=		databases
PGSQL_SITES=		http://www.postgresql.org/ftpsite/ \
			ftp://ftp.postgresql.org/pub/ \
			ftp://ftp.de.postgresql.org/pub/ \
			ftp://ch.postgresql.org/mirror/postgresql/ \
			ftp://gd.tuwien.ac.at/db/www.postgresql.org/pub/ \
			ftp://looking-glass.usask.ca/pub/postgresql/ \
			ftp://ftp.sunsite.auc.dk/mirrors/postgresql/ \
			ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/
MASTER_SITES?=		${PGSQL_SITES:=source/v${DIST_VERS}/}

MAINTAINER=		jwise@netbsd.org
COMMENT=		ODBC interface to PostgreSQL
HOMEPAGE=		http://odbc.postgresql.org/

CONFLICTS+=		postgresql-[0-6]* postgresql-7.0*

# Version numbering scheme:
#
# DIST_VERS		version number on the postgresql distfile
# BASE_VERS		pkgsrc-mangled version number (convert pl -> .)
#
DIST_VERS?=		7.1.3
BASE_VERS?=		${DIST_VERS}

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

# PG_MB_ENCODING may be set to any of:
#
# SQL_ASCII, EUC_JP, EUC_CN, EUC_KR, EUC_TW, UNICODE, MULE_INTERNAL,
# LATIN1, LATIN2, LATIN3, LATIN4, LATIN5, KOI8, WIN, ALT
#
# This variable controls the language encoding on the backend process.

.if defined(PG_MB_ENCODING)
CONFIGURE_ARGS+=	--enable-multibyte=${PG_MB_ENCODING}
.else
CONFIGURE_ARGS+=	--enable-multibyte	# accept default
.endif

CONFIGURE_ARGS+=	--with-odbc
CONFIGURE_ARGS+=	--with-odbcinst=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ARGS+=	--without-tk

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/pgsql
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/postgresql
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_DIR}

CONFIGURE_ARGS+=	--disable-readline
CONFIGURE_ARGS+=	--enable-locale
CONFIGURE_ARGS+=	--enable-syslog
CONFIGURE_ARGS+=	--with-CXX
CONFIGURE_ARGS+=	--with-template="${LOWER_OPSYS}"

DIRS_TO_BUILD=		src/interfaces/odbc

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor

.include "../../mk/bsd.pkg.mk"
