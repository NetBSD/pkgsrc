# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:57 joerg Exp $
#

PKGREVISION=		1

PERDITION_COMMENT=	LDAP user database module
PERDITION_PKGNAME=	ldap

CONFIGURE_ARGS+=	--with-ldap-includes=${BUILDLINK_PREFIX.openldap}/include
CONFIGURE_ARGS+=	--with-ldap-libs=${BUILDLINK_PREFIX.openldap}/lib

.include "../../databases/openldap/buildlink3.mk"
.include "../perdition/Makefile.common"
