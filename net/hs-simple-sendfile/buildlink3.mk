# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:20 pho Exp $

BUILDLINK_TREE+=	hs-simple-sendfile

.if !defined(HS_SIMPLE_SENDFILE_BUILDLINK3_MK)
HS_SIMPLE_SENDFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-simple-sendfile+=	hs-simple-sendfile>=0.2.30
BUILDLINK_ABI_DEPENDS.hs-simple-sendfile+=	hs-simple-sendfile>=0.2.30nb1
BUILDLINK_PKGSRCDIR.hs-simple-sendfile?=	../../net/hs-simple-sendfile

.include "../../mk/bsd.fast.prefs.mk" # for ${OPSYS}

.include "../../net/hs-network/buildlink3.mk"
.if ${OPSYS} != "FreeBSD" && ${OPSYS} != "Darwin" && ${OPSYS} != "Linux"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.endif
.endif	# HS_SIMPLE_SENDFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-simple-sendfile
