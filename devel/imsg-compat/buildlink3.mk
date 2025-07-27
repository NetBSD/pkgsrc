# $NetBSD: buildlink3.mk,v 1.2 2025/07/27 14:37:37 vins Exp $

BUILDLINK_TREE+=	imsg-compat

.if !defined(IMSG_COMPAT_BUILDLINK3_MK)
IMSG_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imsg-compat+=	imsg-compat>=8.0.0nb3
BUILDLINK_PKGSRCDIR.imsg-compat?=	../../devel/imsg-compat

BUILDLINK_LIBNAME.imsg-compat=	imsg
BUILDLINK_LDADD.imsg-compat=	${BUILDLINK_LIBNAME.imsg-compat:S/^/-l/:S/^-l$//}

.endif	# IMSG_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-imsg-compat
