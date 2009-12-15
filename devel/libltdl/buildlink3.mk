# $NetBSD: buildlink3.mk,v 1.10 2009/12/15 17:35:36 joerg Exp $

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

BUILDLINK_API_DEPENDS.libltdl+=	libltdl>=2.2.6
BUILDLINK_PKGSRCDIR.libltdl?=	../../devel/libltdl

.include "../../mk/dlopen.buildlink3.mk"
.endif
.endif # LIBLTDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libltdl
