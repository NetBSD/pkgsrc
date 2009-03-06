# $NetBSD: buildlink3.mk,v 1.30 2009/03/06 14:28:53 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MONO_BUILDLINK3_MK:=	${MONO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	mono
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmono}
BUILDLINK_PACKAGES+=	mono
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mono

.if ${MONO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.mono+=	mono>=2.2
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono
ALL_ENV+=			MONO_SHARED_DIR=${WRKDIR:Q}
.endif	# MONO_BUILDLINK3_MK

PRINT_PLIST_AWK+=	/^@dirrm lib\/mono\/gac$$/ \
				{ print "@comment in mono: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/mono$$/ \
				{ print "@comment in mono: " $$0; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
