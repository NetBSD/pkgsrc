# $NetBSD: buildlink3.mk,v 1.12 2024/05/09 01:32:31 pho Exp $

BUILDLINK_TREE+=	hs-simple-sendfile

.if !defined(HS_SIMPLE_SENDFILE_BUILDLINK3_MK)
HS_SIMPLE_SENDFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-simple-sendfile+=	hs-simple-sendfile>=0.2.32
BUILDLINK_ABI_DEPENDS.hs-simple-sendfile+=	hs-simple-sendfile>=0.2.32nb2
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
