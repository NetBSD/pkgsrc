# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/10/14 19:03:45 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBLTDL_BUILDLINK3_MK:=	${LIBLTDL_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
_SKIP_LIBLTDL=		yes
.  endif
.else

.if !defined(_SKIP_LIBLTDL)
.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libltdl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibltdl}
BUILDLINK_PACKAGES+=	libltdl

.if !empty(LIBLTDL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libltdl+=	libltdl>=1.5.10
BUILDLINK_PKGSRCDIR.libltdl?=	../../devel/libltdl
.endif	# LIBLTDL_BUILDLINK3_MK
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
