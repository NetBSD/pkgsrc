# $NetBSD: Makefile,v 1.8 2026/08/04 20:29:05 wiz Exp $

COMMENT=		Postfix SMTP server PCRE map module

POSTFIX_LIB=		pcre
POSTFIX_LIBDIR=		src/util
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.pcre}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.pcre}/lib -lpcre			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre}/lib

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
