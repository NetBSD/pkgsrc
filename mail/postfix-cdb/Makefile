# $NetBSD: Makefile,v 1.2 2017/01/21 23:49:01 rillig Exp $
#

COMMENT=		Postfix SMTP server cdb backend module
PKGREVISION=		1

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
