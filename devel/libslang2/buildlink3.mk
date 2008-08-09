# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/08/09 21:22:11 bjs Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSLANG2_BUILDLINK3_MK:=	${LIBSLANG2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libslang2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibslang2}
BUILDLINK_PACKAGES+=	libslang2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libslang2

.if ${LIBSLANG2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libslang2+=	libslang2>=2.1.3
BUILDLINK_PKGSRCDIR.libslang2?=	../../devel/libslang2
BUILDLINK_FNAME_TRANSFORM.libslang2+=	-e 's|include/slang2/|include/|g'
BUILDLINK_TRANSFORM+=		l:slang:slang2
pkgbase:=	libslang2
.  include "../../mk/pkg-build-options.mk"
.endif	# LIBSLANG2_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.libslang2:Mpng)
.  include "../../graphics/png/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libslang2:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libslang2:Moniguruma)
.  include "../../textproc/oniguruma/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
