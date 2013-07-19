# $NetBSD: readline.builtin.mk,v 1.3 2013/07/19 14:35:37 ryoon Exp $
#

BUILTIN_PKG:=	editlinereadline

BUILTIN_FIND_LIBS:=		edit readline history
BUILTIN_FIND_FILES_VAR:=	H_EDITLINE H_READLINE
BUILTIN_FIND_FILES.H_READLINE=	/usr/include/readline/readline.h	\
				/usr/include/readline.h
BUILTIN_FIND_FILES.H_EDITLINE=	/usr/include/editline/readline.h	\
				/usr/include/readline/readline.h
BUILTIN_FIND_GREP.H_EDITLINE=	NetBSD
BUILTIN_FIND_GREP.H_READLINE=	\#define[ 	]*RL_VERSION_MAJOR

.include "../../mk/buildlink3/bsd.builtin.mk"

.if !defined(IS_BUILTIN.editlinereadline)
IS_BUILTIN.editlinereadline=	no
.  if empty(H_EDITLINE:M__nonexistent__) && \
      !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS])
IS_BUILTIN.editline=	yes
IS_BUILTIN.editlinereadline=	yes
.  elif empty(H_READLINE:M__nonexistent__) && \
	   !empty(BUILTIN_LIB_FOUND.readline:M[yY][eE][sS])
IS_BUILTIN.readline=	yes
IS_BUILTIN.editlinereadline=	yes
.  else
IS_BUILTIN.editline=	no
IS_BUILTIN.readline=	no
IS_BUILTIN.editlinereadline=	no
.  endif
.endif

.if !defined(USE_BUILTIN.editlinereadline)
.  if ${PREFER.editlinereadline} == "pkgsrc"
USE_BUILTIN.editlinereadline=	no
.  else
USE_BUILTIN.editlinereadline=	${IS_BUILTIN.editlinereadline}
.  endif
.endif

CHECK_BUILTIN.editlinereadline=	no
.if empty(CHECK_BUILTIN.editlinereadline:M[Nn][Oo])
.  if !empty(USE_BUILTIN.editlinereadline:M[Yy][Ee][Ss])
.    if !empty(_READLINE_TYPE:Meditline)
.      include "../../devel/editline/builtin.mk"
IS_BUILTIN.editlinereadline=	${USE_BUILTIN.editline}
.    else if !empty(_READLINE_TYPE:Mreadline)
.      include "../../devel/readline/builtin.mk"
IS_BUILTIN.editlinereadline=	${USE_BUILTIN.readline}
.    endif
.  endif
.endif
