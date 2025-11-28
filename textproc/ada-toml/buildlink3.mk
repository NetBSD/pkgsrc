# $NetBSD: buildlink3.mk,v 1.1 2025/11/28 20:07:22 dkazankov Exp $

BUILDLINK_TREE+=	ada-toml

.if !defined(ADA_TOML_BUILDLINK3_MK)
ADA_TOML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ada-toml+=	ada-toml-${GNAT_NAME}>=0.5
BUILDLINK_PKGSRCDIR.ada-toml?=		../../textproc/ada-toml
BUILDLINK_DEPMETHOD.ada-toml?=		build

BUILDLINK_CONTENTS_FILTER.ada-toml=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.ada-toml+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-ada-toml
