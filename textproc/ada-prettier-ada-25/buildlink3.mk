# $NetBSD: buildlink3.mk,v 1.3 2025/10/12 09:30:46 dkazankov Exp $

BUILDLINK_TREE+=	prettier-ada-25

.if !defined(PRETTIER_ADA_25_BUILDLINK3_MK)
PRETTIER_ADA_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.prettier-ada-25+=		prettier-ada-${GNAT_NAME}>=25.0.0
BUILDLINK_ABI_DEPENDS.prettier-ada-25+=		prettier-ada-${GNAT_NAME}>=25.2.0
BUILDLINK_PKGSRCDIR.prettier-ada-25?=		../../textproc/ada-prettier-ada-25
BUILDLINK_DEPMETHOD.prettier-ada-25?=		build

BUILDLINK_CONTENTS_FILTER.prettier-ada-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.prettier-ada-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-prettier-ada-25
