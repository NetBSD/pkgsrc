# $NetBSD: buildlink3.mk,v 1.2 2025/09/04 09:24:55 dkazankov Exp $

BUILDLINK_TREE+=	prettier-ada-25

.if !defined(PRETTIER_ADA_25_BUILDLINK3_MK)
PRETTIER_ADA_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.prettier-ada-25+=		prettier-ada-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.prettier-ada-25?=		../../textproc/ada-prettier-ada-25
BUILDLINK_DEPMETHOD.prettier-ada-25?=		build

BUILDLINK_CONTENTS_FILTER.prettier-ada-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.prettier-ada-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-prettier-ada-25
