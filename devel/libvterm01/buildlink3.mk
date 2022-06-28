# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:48 wiz Exp $

BUILDLINK_TREE+=	libvterm01

.if !defined(LIBVTERM01_BUILDLINK3_MK)
LIBVTERM01_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvterm01+=	libvterm01>=0.0.0
BUILDLINK_ABI_DEPENDS.libvterm01+=	libvterm01>=0.1.4nb2
BUILDLINK_PKGSRCDIR.libvterm01?=	../../devel/libvterm01
BUILDLINK_INCDIRS.libvterm01+=		include/libvterm01
BUILDLINK_LIBDIRS.libvterm01+=		lib/libvterm01

BUILDLINK_TARGETS+=	buildlink-vterm-unversioned

buildlink-vterm-unversioned:
	${LN} -s ${BUILDLINK_DIR}/lib/pkgconfig/vterm01.pc \
	    ${BUILDLINK_DIR}/lib/pkgconfig/vterm.pc

.endif	# LIBVTERM01_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvterm01
