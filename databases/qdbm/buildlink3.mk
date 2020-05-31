# $NetBSD: buildlink3.mk,v 1.15 2020/05/31 16:38:00 rillig Exp $

BUILDLINK_TREE+=	qdbm

.if !defined(QDBM_BUILDLINK3_MK)
QDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qdbm+=	qdbm>=1.8.40
BUILDLINK_ABI_DEPENDS.qdbm+=	qdbm>=1.8.65
BUILDLINK_PKGSRCDIR.qdbm?=	../../databases/qdbm

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
.if ${GNU_CONFIGURE_PTHREAD:Uyes:tl} == yes
CONFIGURE_ARGS+=		--enable-pthread
.endif
BUILDLINK_CFLAGS.qdbm+=		${PTHREAD_CFLAGS}
BUILDLINK_LDFLAGS.qdbm+=	${PTHREAD_LDFLAGS}
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # QDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-qdbm
