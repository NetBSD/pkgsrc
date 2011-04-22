# $NetBSD: buildlink3.mk,v 1.17 2011/04/22 13:41:59 obache Exp $

BUILDLINK_TREE+=	aspell

.if !defined(ASPELL_BUILDLINK3_MK)
ASPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aspell+=	aspell>=0.50.3
BUILDLINK_ABI_DEPENDS.aspell+=	aspell>=0.60.6nb3
BUILDLINK_PKGSRCDIR.aspell?=	../../textproc/aspell

BUILDLINK_FILES.aspell=	bin/aspell bin/prezip-bin bin/word-list-compress

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # ASPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-aspell
