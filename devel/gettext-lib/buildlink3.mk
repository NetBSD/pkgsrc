# $NetBSD: buildlink3.mk,v 1.30 2008/02/27 22:10:34 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GETTEXT_BUILDLINK3_MK:=	${GETTEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gettext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngettext}
BUILDLINK_PACKAGES+=	gettext
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gettext

.if !empty(GETTEXT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.14.5
BUILDLINK_PKGSRCDIR.gettext?=	../../devel/gettext-lib
BUILDLINK_LIBNAME.gettext=	intl
BUILDLINK_LDADD.gettext=	${BUILDLINK_LIBNAME.gettext:S/^/-l/:S/^-l$//}
BUILDLINK_LDADD.gettext+=	${BUILDLINK_LDADD.iconv}
.endif	# GETTEXT_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

# Some GNU configure scripts generated with an older and broken gettext.m4
# fail to detect if gettext is present or not because it fails to add
# "-lintl" to the linker command line.
#
# If BROKEN_GETTEXT_DETECTION is "yes", then automatically add "-lintl"
# to LIBS to workaround this brokenness.
#
BROKEN_GETTEXT_DETECTION?=	no
.  if !empty(BROKEN_GETTEXT_DETECTION:M[yY][eE][sS])
BUILDLINK_LIBS.gettext+=	${BUILDLINK_LDADD.gettext}
CONFIGURE_ENV+=			INTLLIBS="${BUILDLINK_LDADD.gettext}"
.  endif

CHECK_BUILTIN.gettext:=	yes
.include "../../devel/gettext-lib/builtin.mk"
CHECK_BUILTIN.gettext:=	no

# A built-in gettext is always going to use a built-in iconv.
.if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.iconv=	yes
.endif

.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
