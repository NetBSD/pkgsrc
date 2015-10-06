# $NetBSD: Makefile,v 1.1.2.1 2015/10/06 18:41:34 spz Exp $
#

PKGREVISION=		1
COMMENT=		Postfix SMTP server PostgreSQL backend module

POSTFIX_LIB=		pgsql
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${PGSQL_PREFIX}/include
AUXLIBS_MODULE=		-L${PGSQL_PREFIX}/lib -lpq				\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pgsql}/lib

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
