# $NetBSD: buildlink3.mk,v 1.9 2006/02/05 23:10:59 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ASPELL_BUILDLINK3_MK:=	${ASPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	aspell
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Naspell}
BUILDLINK_PACKAGES+=	aspell

.if !empty(ASPELL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.aspell+=	aspell>=0.50.3
BUILDLINK_RECOMMENDED.aspell+=	aspell>=0.60.4nb1
BUILDLINK_PKGSRCDIR.aspell?=	../../textproc/aspell
.endif	# ASPELL_BUILDLINK3_MK

BUILDLINK_FILES.aspell=	bin/aspell bin/prezip-bin bin/word-list-compress

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
