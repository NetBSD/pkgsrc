# $NetBSD: buildlink.mk,v 1.2 2002/07/12 20:41:16 wiz Exp $
#
# This Makefile fragment is included by packages that use kth-krb4.
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(KTHKRB4_BUILDLINK_MK)
KTHKRB4_BUILDLINK_MK=   # defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.kth-krb4?=	kth-krb4>=1.1.1
DEPENDS+=			${BUILDLINK_DEPENDS.kth-krb4}:../../security/kth-krb4
EVAL_PREFIX+=			BUILDLINK_PREFIX.kth-krb4=kth-krb4

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

pre-configure: kth-krb4-buildlink
kth-krb4-buildlink: _BUILDLINK_USE

.endif	# KTHKRB4_BUILDLINK_MK
