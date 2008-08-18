# $NetBSD: buildlink3.mk,v 1.22 2008/08/18 21:35:37 tron Exp $

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
.  if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.  endif
.endif	# PNG_BUILDLINK3_MK

# Work around broken libtool archive "/usr/X11/lib/libpng12.la" under
# Mac OS 10.5.4 or newer which references a non-existing version of the
# PNG shared library.
.if !empty(MACHINE_PLATFORM:MDarwin-9.*-*)
BUILDLINK_TRANSFORM+=	rename:-lpng12.0.26.0:-lpng
.endif

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
