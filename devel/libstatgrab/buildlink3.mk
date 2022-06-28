# $NetBSD: buildlink3.mk,v 1.11 2022/06/28 11:31:47 wiz Exp $

BUILDLINK_TREE+=	libstatgrab

.if !defined(LIBSTATGRAB_BUILDLINK3_MK)
LIBSTATGRAB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstatgrab+=	libstatgrab>=0.10
BUILDLINK_ABI_DEPENDS.libstatgrab+=	libstatgrab>=0.92nb3
BUILDLINK_PKGSRCDIR.libstatgrab?=	../../devel/libstatgrab

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no

.include "../../devel/log4cplus/buildlink3.mk"
.endif # LIBSTATGRAB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstatgrab
