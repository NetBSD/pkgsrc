# $NetBSD: Makefile,v 1.8 2010/06/02 12:50:04 adam Exp $

PERDITION_COMMENT=	LDAP user database module
PERDITION_PKGNAME=	ldap

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-ldap-includes=${BUILDLINK_PREFIX.openldap-client}/include
CONFIGURE_ARGS+=	--with-ldap-libs=${BUILDLINK_PREFIX.openldap-client}/lib

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/ldap/perditiondb_ldap_makedb

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
