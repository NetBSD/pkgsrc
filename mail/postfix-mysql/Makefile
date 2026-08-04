# $NetBSD: Makefile,v 1.10 2026/08/04 20:29:05 wiz Exp $

COMMENT=		Postfix SMTP server MySQL backend module

POSTFIX_LIB=		mysql
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.mysql-client}/lib -lmysqlclient	\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
