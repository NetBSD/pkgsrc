# $NetBSD: buildlink3.mk,v 1.42 2022/08/11 13:37:24 jperkin Exp $

BUILDLINK_TREE+=	gettext

.if !defined(GETTEXT_BUILDLINK3_MK)
GETTEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.18
BUILDLINK_ABI_DEPENDS.gettext+=	gettext-lib>=0.18
BUILDLINK_PKGSRCDIR.gettext?=	../../devel/gettext-lib
BUILDLINK_LIBNAME.gettext=	intl
BUILDLINK_LDADD.gettext=	${BUILDLINK_LIBNAME.gettext:S/^/-l/:S/^-l$//}
BUILDLINK_LDADD.gettext+=	${BUILDLINK_LDADD.iconv}

.include "../../mk/bsd.fast.prefs.mk"

# Some GNU configure scripts generated with an older and broken gettext.m4
# fail to detect if gettext is present or not because it fails to add
# "-lintl" to the linker command line.
#
# If BROKEN_GETTEXT_DETECTION is "yes", then automatically add "-lintl"
# to LIBS to workaround this brokenness.
#
BROKEN_GETTEXT_DETECTION?=	no
.if !empty(BROKEN_GETTEXT_DETECTION:M[yY][eE][sS])
BUILDLINK_LIBS.gettext+=	${BUILDLINK_LDADD.gettext}
CONFIGURE_ENV+=			INTLLIBS="${BUILDLINK_LDADD.gettext}"
.endif

#
# Due to Linux shipping libintl in libc, third-party software often forgets to
# explicitly look for and add -lintl when required.  On systems that use GNU
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
BUILDLINK_LDFLAGS.gettext+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gettext}/lib
BUILDLINK_LDFLAGS.gettext+=	${BUILDLINK_LDADD.gettext}
.endif

CHECK_BUILTIN.gettext:=	yes
.include "../../devel/gettext-lib/builtin.mk"
CHECK_BUILTIN.gettext:=	no

# A built-in gettext is always going to use a built-in iconv.
.if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.iconv=			yes
.else
#BUILDLINK_INCDIRS.gettext+=		include/gettext
BUILDLINK_FNAME_TRANSFORM.gettext+=	-e 's|include/gettext/|include/|'
.endif

.include "../../converters/libiconv/buildlink3.mk"
.endif # GETTEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gettext
