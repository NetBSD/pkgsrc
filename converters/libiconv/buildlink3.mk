# $NetBSD: buildlink3.mk,v 1.28 2022/08/11 13:37:24 jperkin Exp $

BUILDLINK_TREE+=	iconv

.if !defined(ICONV_BUILDLINK3_MK)
ICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iconv+=	libiconv>=1.9.1
BUILDLINK_ABI_DEPENDS.iconv+=	libiconv>=1.9.1nb4
BUILDLINK_PKGSRCDIR.iconv?=	../../converters/libiconv
BUILDLINK_LIBNAME.iconv=	iconv
BUILDLINK_LDADD.iconv=		${BUILDLINK_LIBNAME.iconv:S/^/-l/:S/^-l$//}

.include "../../mk/bsd.fast.prefs.mk"

#
# Due to Linux shipping libiconv in libc, third-party software often forgets to
# explicitly look for and add -liconv when required.  On systems that use GNU
# ld this isn't always an issue as it will often be pulled in via an explicit
# library, but some systems have a stricter linker that will not pull in
# symbols via implicit dependencies, and so we need to explicitly link here.
#
# Ideally this would be done via CWRAPPERS_LDADD to avoid leaking into LDFLAGS
# but there is no concensus on that yet.
#
# USE_EXPLICIT_LIBDEPS is a package-settable variable for rare cases where the
# libraries need to be pulled in but we do not want to expose them by default.
#
.if ${OPSYS_EXPLICIT_LIBDEPS:Uno:tl} == "yes" && ${USE_EXPLICIT_LIBDEPS:Uyes:tl} != "no"
BUILDLINK_LDFLAGS.iconv+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.iconv}/lib
BUILDLINK_LDFLAGS.iconv+=	${BUILDLINK_LDADD.iconv}
.endif

.endif # ICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-iconv
