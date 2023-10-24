# $NetBSD: Makefile,v 1.16 2023/10/24 22:09:48 wiz Exp $

PKGREVISION=		7
PERDITION_COMMENT=	LDAP user database module
PERDITION_PKGNAME=	ldap

CONFIGURE_ARGS+=	--with-ldap-includes=${BUILDLINK_PREFIX.openldap-client}/include
CONFIGURE_ARGS+=	--with-ldap-libs=${BUILDLINK_PREFIX.openldap-client}/lib

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/ldap/perditiondb_ldap_makedb

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
