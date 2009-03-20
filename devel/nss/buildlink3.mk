# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:25 joerg Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=		nss>=3.9.2nb1
BUILDLINK_ABI_DEPENDS.nss+=	nss>=3.9.2nb4
BUILDLINK_PKGSRCDIR.nss?=	../../devel/nss

BUILDLINK_FILES.nss+=		lib/nss/*
BUILDLINK_FILES.nss+=		include/nss/*

BUILDLINK_INCDIRS.nss+=		include/nss
BUILDLINK_LIBDIRS.nss+=		lib/nss
BUILDLINK_RPATHDIRS.nss+=	lib/nss

.include "../../devel/nspr/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
