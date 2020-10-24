# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:47 wiz Exp $

COLLECTD_PACKAGE=	openldap

COMMENT=		Statistics collection daemon - openldap plugin

.include "../../databases/openldap-client/buildlink3.mk"
COLLECTD_LIB.ldap=	${BUILDLINK_PREFIX.openldap-client}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
