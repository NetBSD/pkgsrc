# $NetBSD: Makefile,v 1.3 2017/03/04 06:26:42 taca Exp $
#

COMMENT=		Postfix SMTP server cdb backend module

POSTFIX_LIB=		cdb
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	yes

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.tinycdb}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.tinycdb}/lib -lcdb			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tinycdb}/lib

.include "../../databases/tinycdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
