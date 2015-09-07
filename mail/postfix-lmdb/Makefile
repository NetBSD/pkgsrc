# $NetBSD: Makefile,v 1.1 2015/09/07 09:47:02 fhajny Exp $
#

COMMENT=		Postfix SMTP server LMDB backend module

POSTFIX_LIB=		lmdb
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	yes

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.lmdb}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.lmdb}/lib -llmdb			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.}/lib

.include "../../databases/lmdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
