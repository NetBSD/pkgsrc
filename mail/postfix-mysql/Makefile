# $NetBSD: Makefile,v 1.9 2023/12/22 17:29:17 wiz Exp $

COMMENT=		Postfix SMTP server MySQL backend module

POSTFIX_LIB=		mysql
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.mysql-client}/lib -lmysqlclient	\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
