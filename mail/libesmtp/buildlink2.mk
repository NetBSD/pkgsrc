# $NetBSD: buildlink2.mk,v 1.3 2003/05/02 11:55:39 wiz Exp $

.if !defined(LIBESMTP_BUILDLINK2_MK)
LIBESMTP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libesmtp
BUILDLINK_DEPENDS.libesmtp?=	libesmtp>=1.0rc1nb1
BUILDLINK_PKGSRCDIR.libesmtp?=	../../mail/libesmtp

EVAL_PREFIX+=	BUILDLINK_PREFIX.libesmtp=libesmtp
BUILDLINK_PREFIX.libesmtp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libesmtp=	include/libesmtp.h
BUILDLINK_FILES.libesmtp+=	include/auth-client.h
BUILDLINK_FILES.libesmtp+=	include/auth-plugin.h
BUILDLINK_FILES.libesmtp+=	lib/libesmtp.*
LIBESMTP=			-lesmtp

CONFIGURE_ENV+=			LIBESMTP="${LIBESMTP}"
MAKE_ENV+=			LIBESMTP="${LIBESMTP}"

BUILDLINK_TARGETS+=		libesmtp-buildlink

libesmtp-buildlink: _BUILDLINK_USE

.endif	# LIBESMTP_BUILDLINK2_MK
