# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:48 jlam Exp $
#
# This Makefile fragment is included by packages that use cyrus-sasl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.cyrus-sasl to the dependency pattern
#     for the version of cyrus-sasl desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(CYRUS_SASL_BUILDLINK2_MK)
CYRUS_SASL_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.cyrus-sasl?=	cyrus-sasl>=1.5.24nb2
DEPENDS+=	${BUILDLINK_DEPENDS.cyrus-sasl}:../../security/cyrus-sasl

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
