# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/04/11 00:08:11 rh Exp $

.if !defined(GNUSTEP_SSL_BUILDLINK2_MK)
GNUSTEP_SSL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnustep-ssl
BUILDLINK_DEPENDS.gnustep-ssl?=		gnustep-ssl>=1.9.1
BUILDLINK_PKGSRCDIR.gnustep-ssl?=	../../security/gnustep-ssl

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-ssl=gnustep-ssl
BUILDLINK_PREFIX.gnustep-ssl_DEFAULT=	${LOCALBASE}

.include "../../devel/gnustep-base/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	gnustep-ssl-buildlink

gnustep-ssl-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_SSL_BUILDLINK2_MK
