# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:28 tv Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.hdf5?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HDF5_BUILDLINK3_MK:=	${HDF5_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	hdf5
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhdf5}
BUILDLINK_PACKAGES+=	hdf5

.if !empty(HDF5_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.hdf5+=	hdf5>=1.6.2
BUILDLINK_RECOMMENDED.hdf5+=	hdf5>=1.6.2nb1
BUILDLINK_PKGSRCDIR.hdf5?=	../../devel/hdf5
.endif	# HDF5_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
