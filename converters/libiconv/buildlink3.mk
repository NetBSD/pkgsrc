# $NetBSD: buildlink3.mk,v 1.26 2009/03/20 19:24:03 joerg Exp $

BUILDLINK_TREE+=	iconv

.if !defined(ICONV_BUILDLINK3_MK)
ICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iconv+=	libiconv>=1.9.1
BUILDLINK_ABI_DEPENDS.iconv+=	libiconv>=1.9.1nb4
BUILDLINK_PKGSRCDIR.iconv?=	../../converters/libiconv
BUILDLINK_LIBNAME.iconv=	iconv
BUILDLINK_LDADD.iconv=		${BUILDLINK_LIBNAME.iconv:S/^/-l/:S/^-l$//}
.endif # ICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-iconv
