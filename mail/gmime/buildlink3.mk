# $NetBSD: buildlink3.mk,v 1.21 2017/03/16 00:34:46 gdt Exp $

BUILDLINK_TREE+=	gmime

.if !defined(GMIME_BUILDLINK3_MK)
GMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.6.15
BUILDLINK_PKGSRCDIR.gmime?=	../../mail/gmime

.include "../../devel/glib2/buildlink3.mk"
# gmime-2.6.pc specifies linking with gpgme's libs.  While this is arguably
# wrong and should perhaps be patched, until then we should include them
# here.
.include "../../security/gpgme/buildlink3.mk"
.endif # GMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime
