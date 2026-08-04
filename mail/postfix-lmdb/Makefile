# $NetBSD: Makefile,v 1.9 2026/08/04 20:29:05 wiz Exp $

COMMENT=		Postfix SMTP server LMDB backend module

POSTFIX_LIB=		lmdb
POSTFIX_LIBDIR=		src/util
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	yes

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.lmdb}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.lmdb}/lib -llmdb			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.lmdb}/lib

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../databases/lmdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
