# $NetBSD: buildlink3.mk,v 1.7 2004/12/31 14:26:47 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ASPELL_BUILDLINK3_MK:=	${ASPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	aspell
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Naspell}
BUILDLINK_PACKAGES+=	aspell

.if !empty(ASPELL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.aspell+=	aspell>=0.60.2
BUILDLINK_PKGSRCDIR.aspell?=	../../textproc/aspell
.endif	# ASPELL_BUILDLINK3_MK

BUILDLINK_FILES.aspell=	bin/aspell bin/prezip-bin bin/word-list-compress

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
