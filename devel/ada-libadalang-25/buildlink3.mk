# $NetBSD: buildlink3.mk,v 1.3 2025/11/06 06:53:52 dkazankov Exp $

BUILDLINK_TREE+=	libadalang-25

.if !defined(LIBADALANG_25_BUILDLINK3_MK)
LIBADALANG_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libadalang-25+=		libadalang-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.libadalang-25?=		../../devel/ada-libadalang-25
BUILDLINK_DEPMETHOD.libadalang-25?=		build

BUILDLINK_CONTENTS_FILTER.libadalang-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.libadalang-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"
.include "../../devel/ada-langkit-support-25/buildlink3.mk"

.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.endif

BUILDLINK_TREE+=	-libadalang-25
