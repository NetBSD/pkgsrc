# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:50 jlam Exp $

.if !defined(CYRUS_SASL_BUILDLINK2_MK)
CYRUS_SASL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			cyrus-sasl
BUILDLINK_DEPENDS.cyrus-sasl?=		cyrus-sasl>=1.5.24nb2
BUILDLINK_PKGSRCDIR.cyrus-sasl?=	../../security/cyrus-sasl

EVAL_PREFIX+=	BUILDLINK_PREFIX.cyrus-sasl=cyrus-sasl
BUILDLINK_PREFIX.cyrus-sasl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cyrus-sasl=	include/hmac-md5.h
BUILDLINK_FILES.cyrus-sasl+=	include/sasl.h
BUILDLINK_FILES.cyrus-sasl+=	include/saslplug.h
BUILDLINK_FILES.cyrus-sasl+=	include/saslutil.h
BUILDLINK_FILES.cyrus-sasl+=	lib/libsasl.*

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	cyrus-sasl-buildlink

cyrus-sasl-buildlink: _BUILDLINK_USE

.endif	# CYRUS_SASL_BUILDLINK2_MK
