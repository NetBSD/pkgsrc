# $NetBSD: buildlink3.mk,v 1.8 2006/12/12 21:52:35 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBLTDL_BUILDLINK3_MK:=	${LIBLTDL_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
_SKIP_LIBLTDL=		yes
.  endif
.endif

.if !defined(_SKIP_LIBLTDL)
.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libltdl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibltdl}
BUILDLINK_PACKAGES+=	libltdl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libltdl

.if !empty(LIBLTDL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libltdl+=	libltdl>=1.5.10
BUILDLINK_PKGSRCDIR.libltdl?=	../../devel/libltdl
.endif	# LIBLTDL_BUILDLINK3_MK

.include "../../mk/dlopen.buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
