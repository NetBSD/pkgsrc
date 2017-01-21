# $NetBSD: Makefile,v 1.7 2017/01/21 23:49:02 rillig Exp $
#

PKGREVISION=		1
COMMENT=		Postfix SMTP server SQLite backend module

POSTFIX_LIB=		sqlite
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.sqlite3}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3		\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
