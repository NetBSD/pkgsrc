# $NetBSD: buildlink3.mk,v 1.6 2005/05/20 19:20:55 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBAO_BUILDLINK3_MK:=	${LIBAO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libao
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibao}
BUILDLINK_PACKAGES+=	libao

.if !empty(LIBAO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libao+=	libao>=0.8.4
BUILDLINK_RECOMMENDED.libao+=	libao>=0.8.4nb1
BUILDLINK_PKGSRCDIR.libao?=	../../audio/libao
.endif	# LIBAO_BUILDLINK3_MK

PRINT_PLIST_AWK+=	/^@dirrm lib\/ao\/plugins-2$$/ \
				{ print "@comment in libao: " $$0; next }

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
