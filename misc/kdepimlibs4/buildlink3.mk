# $NetBSD: buildlink3.mk,v 1.70 2020/11/05 09:07:00 ryoon Exp $

BUILDLINK_TREE+=	kdepimlibs

.if !defined(KDEPIMLIBS_BUILDLINK3_MK)
KDEPIMLIBS_BUILDLINK3_MK:=

# Hack to not find wrong gpgme++
pre-configure: kdepimlibs4-preconfigure
kdepimlibs4-preconfigure:
	mv ${BUILDLINK_DIR}/include/gpgme++ ${BUILDLINK_DIR}/include/gpgme++.xxx

BUILDLINK_API_DEPENDS.kdepimlibs+=	kdepimlibs4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdepimlibs+=	kdepimlibs4>=4.14.10nb28
BUILDLINK_PKGSRCDIR.kdepimlibs?=	../../misc/kdepimlibs4

.include "../../mk/bsd.fast.prefs.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../mail/akonadi/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDEPIMLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepimlibs
