# $NetBSD: buildlink2.mk,v 1.2 2004/04/07 13:18:31 salo Exp $

.if !defined(MITKRB5_BUILDLINK2_MK)
MITKRB5_BUILDLINK2_MK=   # defined

BUILDLINK_PACKAGES+=		mit-krb5
BUILDLINK_DEPENDS.mit-krb5?=	mit-krb5>=1.3.1
BUILDLINK_PKGSRCDIR.mit-krb5?=	../../security/mit-krb5

EVAL_PREFIX+=				BUILDLINK_PREFIX.mit-krb5=mit-krb5
BUILDLINK_PREFIX.mit-krb5_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.mit-krb5=	include/com_err.h
BUILDLINK_FILES.mit-krb5+=	include/kerberosIV/*
BUILDLINK_FILES.mit-krb5+=	include/gssapi/*
BUILDLINK_FILES.mit-krb5+=	include/krb5.h
BUILDLINK_FILES.mit-krb5+=	include/profile.h
BUILDLINK_FILES.mit-krb5+=	lib/libcom_err.*
BUILDLINK_FILES.mit-krb5+=	lib/libdes425.*
BUILDLINK_FILES.mit-krb5+=	lib/libgssapi_krb5.*
BUILDLINK_FILES.mit-krb5+=	lib/libgssrpc.*
BUILDLINK_FILES.mit-krb5+=	lib/libk5crypto.*
BUILDLINK_FILES.mit-krb5+=	lib/libkadm5clnt.*
BUILDLINK_FILES.mit-krb5+=	lib/libkadm5srv.*
BUILDLINK_FILES.mit-krb5+=	lib/libkdb5.*
BUILDLINK_FILES.mit-krb5+=	lib/libkrb4.*
BUILDLINK_FILES.mit-krb5+=	lib/libkrb5.*

BUILDLINK_TARGETS+=             mit-krb5-buildlink

mit-krb5-buildlink: _BUILDLINK_USE

.endif	# MITKRB5_BUILDLINK2_MK
