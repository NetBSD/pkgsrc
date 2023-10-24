# $NetBSD: Makefile,v 1.2 2023/10/24 22:11:05 wiz Exp $

COLLECTD_PACKAGE=	openldap

COMMENT=		Statistics collection daemon - openldap plugin
PKGREVISION=		1

.include "../../databases/openldap-client/buildlink3.mk"
COLLECTD_LIB.ldap=	${BUILDLINK_PREFIX.openldap-client}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
