# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:52 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBKIPI_BUILDLINK3_MK:=	${LIBKIPI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libkipi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibkipi}
BUILDLINK_PACKAGES+=	libkipi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libkipi

.if !empty(LIBKIPI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libkipi+=	libkipi>=0.1
BUILDLINK_ABI_DEPENDS.libkipi?=	libkipi>=0.1.2nb3
BUILDLINK_PKGSRCDIR.libkipi?=	../../graphics/libkipi

.  for dir in share/kde/apps/kipi/data share/kde/apps/kipi
PRINT_PLIST_AWK+=	/^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in libkipi: " $$0; next; }
.  endfor
.endif	# LIBKIPI_BUILDLINK3_MK

.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
