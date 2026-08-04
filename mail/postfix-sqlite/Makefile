# $NetBSD: Makefile,v 1.48 2026/08/04 20:29:06 wiz Exp $

COMMENT=		Postfix SMTP server SQLite backend module

POSTFIX_LIB=		sqlite
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.sqlite3}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3		\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
