# $NetBSD: buildlink3.mk,v 1.38 2019/06/08 09:34:29 jperkin Exp $

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
# to LIBS to workaround this brokenness.  This is also the default on SunOS
# due to stricter linker requirements for implicit libraries.
#
BROKEN_GETTEXT_DETECTION?=	no
.if !empty(BROKEN_GETTEXT_DETECTION:M[yY][eE][sS]) || ${OPSYS} == "SunOS"
BUILDLINK_LDFLAGS.gettext+=	${BUILDLINK_LDADD.gettext}
CONFIGURE_ENV+=			INTLLIBS="${BUILDLINK_LDADD.gettext}"
.endif

CHECK_BUILTIN.gettext:=	yes
.include "../../devel/gettext-lib/builtin.mk"
CHECK_BUILTIN.gettext:=	no

# A built-in gettext is always going to use a built-in iconv.
.if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.iconv=	yes
.else
#BUILDLINK_INCDIRS.gettext+= include/gettext
BUILDLINK_FNAME_TRANSFORM.gettext+=    -e 's|include/gettext/|include/|'
.endif

.include "../../converters/libiconv/buildlink3.mk"
.endif # GETTEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gettext
