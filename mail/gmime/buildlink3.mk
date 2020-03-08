# $NetBSD: buildlink3.mk,v 1.23 2020/03/08 16:47:53 wiz Exp $

BUILDLINK_TREE+=	gmime

.if !defined(GMIME_BUILDLINK3_MK)
GMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.6.15
BUILDLINK_ABI_DEPENDS.gmime?=	gmime>=2.6.23nb3
BUILDLINK_PKGSRCDIR.gmime?=	../../mail/gmime

.include "../../devel/glib2/buildlink3.mk"
# gmime-2.6.pc specifies linking with gpgme's libs.  While this is arguably
# wrong and should perhaps be patched, until then we should include them
# here.
.include "../../security/gpgme/buildlink3.mk"
.endif # GMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime
