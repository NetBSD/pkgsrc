# $NetBSD: Makefile,v 1.6 2016/10/09 21:42:00 wiz Exp $
#

COMMENT=		Postfix SMTP server PostgreSQL backend module
PKGREVISION=		1

POSTFIX_LIB=		pgsql
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${PGSQL_PREFIX}/include
AUXLIBS_MODULE=		-L${PGSQL_PREFIX}/lib -lpq				\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
