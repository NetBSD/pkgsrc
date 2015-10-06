# $NetBSD: Makefile,v 1.1.2.1 2015/10/06 18:41:34 spz Exp $
#

PKGREVISION=		1
COMMENT=		Postfix SMTP server LMDB backend module

POSTFIX_LIB=		lmdb
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	yes

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.lmdb}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.lmdb}/lib -llmdb			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.lmdb}/lib

.include "../../databases/lmdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
