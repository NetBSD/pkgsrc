# $NetBSD: Makefile,v 1.4 2023/05/08 04:31:44 triaxx Exp $
#

COMMENT=		Postfix SMTP server cdb backend module

POSTFIX_LIB=		cdb
POSTFIX_LIBDIR=		src/util
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	yes

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.tinycdb}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.tinycdb}/lib -lcdb			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tinycdb}/lib

.include "../../databases/tinycdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
