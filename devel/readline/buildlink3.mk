# $NetBSD: buildlink3.mk,v 1.33 2011/02/23 11:00:17 adam Exp $

BUILDLINK_TREE+=	readline

.if !defined(READLINE_BUILDLINK3_MK)
READLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.readline+=	readline>=2.2
BUILDLINK_ABI_DEPENDS.readline+=	readline>=6.0
BUILDLINK_PKGSRCDIR.readline?=		../../devel/readline

BUILDLINK_FILES.readline+=	include/history.h
BUILDLINK_FILES.readline+=	include/readline.h

BUILDLINK_FNAME_TRANSFORM.readline+=	-e 's|include/history\.h|include/readline/history.h|g'
BUILDLINK_FNAME_TRANSFORM.readline+=	-e 's|include/readline\.h|include/readline/readline.h|g'

# Many GNU configure scripts don't check for the correct terminal library
# when testing for -lreadline.  If BROKEN_READLINE_DETECTION is set to
# "yes", then automatically add the right one.
.  include "../../mk/bsd.fast.prefs.mk"
BROKEN_READLINE_DETECTION?=	no
.if !empty(BROKEN_READLINE_DETECTION:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=		l:readline:readline:${BUILDLINK_LIBNAME.termcap}
.endif

CHECK_BUILTIN.readline:=	yes
.include "../../devel/readline/builtin.mk"
CHECK_BUILTIN.readline:=	no

# A built-in readline is always going to use a built-in termcap.
.if !empty(USE_BUILTIN.readline:M[yY][eE][sS])
USE_BUILTIN.termcap=	yes
.endif

.include "../../mk/termcap.buildlink3.mk"
.endif # READLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-readline
