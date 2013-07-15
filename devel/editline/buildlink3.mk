# $NetBSD: buildlink3.mk,v 1.1 2013/07/15 01:42:47 ryoon Exp $

BUILDLINK_TREE+=	editline

.if !defined(EDITLINE_BUILDLINK3_MK)
EDITLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.editline+=	editline>=3.0.20130712
BUILDLINK_PKGSRCDIR.editline?=	../../devel/editline

BUILDLINK_FILES.editline+=	include/history.h
BUILDLINK_FILES.editline+=	include/readline.h

BUILDLINK_FNAME_TRANSFORM.editline+=	-e 's|include/editline/readline\.h|include/readline/history.h|g'
BUILDLINK_FNAME_TRANSFORM.editline+=	-e 's|include/editline/readline\.h|include/readline/readline.h|g'

CHECK_BUILTIN.editline:=	yes
.include "../../devel/editline/builtin.mk"
CHECK_BUILTIN.editline:=	no

USE_BUILTIN.termcap=	yes

.include "../../mk/termcap.buildlink3.mk"
.endif	# EDITLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-editline
