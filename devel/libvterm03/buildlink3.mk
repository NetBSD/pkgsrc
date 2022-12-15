# $NetBSD: buildlink3.mk,v 1.1 2022/12/15 22:13:50 nikita Exp $

BUILDLINK_TREE+=	libvterm03

.if !defined(LIBVTERM03_BUILDLINK3_MK)
LIBVTERM03_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvterm03+=	libvterm03>=0.0.0
BUILDLINK_ABI_DEPENDS.libvterm03+=	libvterm03>=0.3
BUILDLINK_PKGSRCDIR.libvterm03?=	../../devel/libvterm03
BUILDLINK_INCDIRS.libvterm03+=		include/libvterm03
BUILDLINK_LIBDIRS.libvterm03+=		lib/libvterm03

BUILDLINK_TARGETS+=	buildlink-vterm-unversioned

.PHONY: buildlink-vterm-unversioned

buildlink-vterm-unversioned:
	${LN} -s ${BUILDLINK_DIR}/lib/pkgconfig/vterm03.pc \
	    ${BUILDLINK_DIR}/lib/pkgconfig/vterm.pc

.endif	# LIBVTERM03_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvterm03
