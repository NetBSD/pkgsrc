# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:40 jlam Exp $

.if !defined(KTHKRB4_BUILDLINK2_MK)
KTHKRB4_BUILDLINK2_MK=   # defined 

BUILDLINK_PACKAGES+=		kth-krb4
BUILDLINK_DEPENDS.kth-krb4?=	kth-krb4>=1.1.1
BUILDLINK_PKGSRCDIR.kth-krb4?=	../../security/kth-krb4

EVAL_PREFIX+=				BUILDLINK_PREFIX.kth-krb4=kth-krb4
BUILDLINK_PREFIX.kth-krb4_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.kth-krb4=	include/kerberosIV/*
BUILDLINK_FILES.kth-krb4+=	lib/libacl.*
BUILDLINK_FILES.kth-krb4+=	lib/libcom_err.*
BUILDLINK_FILES.kth-krb4+=	lib/libdes.*
BUILDLINK_FILES.kth-krb4+=	lib/libkadm.*
BUILDLINK_FILES.kth-krb4+=	lib/libkafs.*
BUILDLINK_FILES.kth-krb4+=	lib/lib/libkdb.*
BUILDLINK_FILES.kth-krb4+=	lib/libkrb.*
BUILDLINK_FILES.kth-krb4+=	lib/libotp.*
BUILDLINK_FILES.kth-krb4+=	lib/libroken.*
BUILDLINK_FILES.kth-krb4+=	lib/libsl.*
BUILDLINK_FILES.kth-krb4+=	lib/libss.*

BUILDLINK_TARGETS+=             kth-krb4-buildlink

kth-krb4-buildlink: _BUILDLINK_USE  

.endif	# KTHKRB4_BUILDLINK2_MK
