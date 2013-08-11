# $NetBSD: buildlink3.mk,v 1.3 2013/08/11 07:42:51 obache Exp $

BUILDLINK_TREE+=	editline

.if !defined(EDITLINE_BUILDLINK3_MK)
EDITLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.editline+=	editline>=3.0.20130712nb1
BUILDLINK_PKGSRCDIR.editline?=	../../devel/editline

BUILDLINK_FILES.editline+=	include/history.h
BUILDLINK_FILES.editline+=	include/readline.h

BUILDLINK_FNAME_TRANSFORM.editline+=	-e 's|include/editline/history\.h|include/readline/history.h|g'
BUILDLINK_FNAME_TRANSFORM.editline+=	-e 's|include/editline/readline\.h|include/readline/readline.h|g'

CHECK_BUILTIN.editline:=	yes
.include "../../devel/editline/builtin.mk"
CHECK_BUILTIN.editline:=	no

# A built-in editline is always going to use a built-in termcap.
.if !empty(USE_BUILTIN.editline:M[yY][eE][sS])
USE_BUILTIN.termcap=	yes
.endif

.include "../../mk/termcap.buildlink3.mk"
.endif	# EDITLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-editline
