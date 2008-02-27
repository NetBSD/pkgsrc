# $NetBSD: buildlink3.mk,v 1.29 2008/02/27 18:16:37 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
READLINE_BUILDLINK3_MK:=	${READLINE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	readline
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nreadline}
BUILDLINK_PACKAGES+=	readline
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}readline

.if !empty(READLINE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.readline+=	readline>=2.2
BUILDLINK_ABI_DEPENDS.readline+=	readline>=5.0
BUILDLINK_PKGSRCDIR.readline?=		../../devel/readline

BUILDLINK_FILES.readline+=	include/history.h
BUILDLINK_FILES.readline+=	include/readline.h

BUILDLINK_FNAME_TRANSFORM.readline+= \
	-e "s|include/history\.h|include/readline/history.h|g"		\
	-e "s|include/readline\.h|include/readline/readline.h|g"

# Many GNU configure scripts don't check for the correct terminal library
# when testing for -lreadline.  If BROKEN_READLINE_DETECTION is set to
# "yes", then automatically add the right one.
#
.  include "../../mk/bsd.fast.prefs.mk"
BROKEN_READLINE_DETECTION?=	no
.  if !empty(BROKEN_READLINE_DETECTION:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=		l:readline:readline:${BUILDLINK_LIBNAME.termlib}
.  endif
.endif	# READLINE_BUILDLINK3_MK

CHECK_BUILTIN.readline:=	yes
.include "../../devel/readline/builtin.mk"
CHECK_BUILTIN.readline:=	no

# A built-in readline is always going to use a built-in termlib.
.if !empty(USE_BUILTIN.readline:M[yY][eE][sS])
USE_BUILTIN.termlib=	yes
.endif

.include "../../mk/termlib.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
