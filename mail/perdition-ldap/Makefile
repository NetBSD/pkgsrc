# $NetBSD: Makefile,v 1.3 2006/05/31 18:52:38 ghen Exp $
#

PKGREVISION=		2

PERDITION_COMMENT=	LDAP user database module
PERDITION_PKGNAME=	ldap

CONFIGURE_ARGS+=	--with-ldap-includes=${BUILDLINK_PREFIX.openldap-client}/include
CONFIGURE_ARGS+=	--with-ldap-libs=${BUILDLINK_PREFIX.openldap-client}/lib

.include "../../databases/openldap-client/buildlink3.mk"
.include "../perdition/Makefile.common"
