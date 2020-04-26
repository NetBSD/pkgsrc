# $NetBSD: Makefile,v 1.7 2020/04/26 09:33:26 taca Exp $
#

COMMENT=		Postfix SMTP server LDAP backend module

POSTFIX_LIB=		ldap
POSTFIX_LIBDIR=		src/global
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.openldap-client}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.openldap-client}/lib -lldap -llber	\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openldap-client}/lib

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
