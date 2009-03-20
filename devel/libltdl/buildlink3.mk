# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:20 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
_SKIP_LIBLTDL=		yes
.  endif
.endif

.if !defined(_SKIP_LIBLTDL)

BUILDLINK_TREE+=	libltdl

.if !defined(LIBLTDL_BUILDLINK3_MK)
LIBLTDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libltdl+=	libltdl>=1.5.10
BUILDLINK_PKGSRCDIR.libltdl?=	../../devel/libltdl

.include "../../mk/dlopen.buildlink3.mk"
.endif
.endif # LIBLTDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libltdl
