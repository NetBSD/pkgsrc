# $NetBSD: buildlink3.mk,v 1.4 2014/04/29 06:18:42 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
	!exists(${X11BASE}/lib/pkgconfig/pciaccess.pc) && \
	!exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/pciaccess.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libpciaccess

.if !defined(LIBPCIACCESS_BUILDLINK3_MK)
LIBPCIACCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpciaccess+=	libpciaccess>=0.10.4
BUILDLINK_PKGSRCDIR.libpciaccess?=	../../sysutils/libpciaccess

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBPCIACCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpciaccess

.endif
