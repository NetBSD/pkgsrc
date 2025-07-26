# $NetBSD: buildlink3.mk,v 1.1 2025/07/26 09:06:46 vins Exp $

BUILDLINK_TREE+=	imsg-compat

.if !defined(IMSG_COMPAT_BUILDLINK3_MK)
IMSG_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imsg-compat+=	imsg-compat>=8.0.0nb1
BUILDLINK_PKGSRCDIR.imsg-compat?=	../../devel/imsg-compat

BUILDLINK_LIBNAME.imsg-compat=	imsg
BUILDLINK_LDADD.imsg-compat=	${BUILDLINK_LIBNAME.imsg-compat:S/^/-l/:S/^-l$//}

.endif	# IMSG_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-imsg-compat
