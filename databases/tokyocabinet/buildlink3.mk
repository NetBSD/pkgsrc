# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/04 12:10:28 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TOKYOCABINET_BUILDLINK3_MK:=	${TOKYOCABINET_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	tokyocabinet
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntokyocabinet}
BUILDLINK_PACKAGES+=	tokyocabinet
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tokyocabinet

.if ${TOKYOCABINET_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.3.7
BUILDLINK_PKGSRCDIR.tokyocabinet?=	../../databases/tokyocabinet
.endif	# TOKYOCABINET_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzmalib/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
