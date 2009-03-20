# $NetBSD: buildlink3.mk,v 1.23 2009/03/20 19:24:44 joerg Exp $

BUILDLINK_TREE+=	png

.if !defined(PNG_BUILDLINK3_MK)
PNG_BUILDLINK3_MK:=

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

# Work around broken libtool archive "/usr/X11/lib/libpng12.la" under
# Mac OS 10.5.4 or newer which references a non-existing version of the
# PNG shared library.
.if !empty(MACHINE_PLATFORM:MDarwin-9.*-*)
BUILDLINK_TRANSFORM+=	rename:-lpng12.0.26.0:-lpng
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif # PNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-png
