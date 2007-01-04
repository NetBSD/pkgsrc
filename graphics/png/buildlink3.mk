# $NetBSD: buildlink3.mk,v 1.17.2.1 2007/01/04 15:09:26 salo Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PNG_BUILDLINK3_MK:=	${PNG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	png
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npng}
BUILDLINK_PACKAGES+=	png
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}png

.if !empty(PNG_BUILDLINK3_MK:M+)
# XXX tv - remove this OPSYS block the next time ABI_DEPENDS is bumped:
.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "Interix"
BUILDLINK_ABI_DEPENDS.png+=	png>=1.2.14nb1 # fixes linkage bug
.  endif

BUILDLINK_API_DEPENDS.png+=	png>=1.2.4
BUILDLINK_ABI_DEPENDS.png+=	png>=1.2.9nb2
BUILDLINK_PKGSRCDIR.png?=	../../graphics/png

# keep this in sync with the same code in Makefile
.  if ${MACHINE_ARCH} != "i386"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.  endif
.endif	# PNG_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
