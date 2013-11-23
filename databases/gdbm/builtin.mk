# $NetBSD: builtin.mk,v 1.2 2013/11/23 11:29:35 obache Exp $

BUILTIN_PKG:=			gdbm
BUILTIN_FIND_HEADERS_VAR=	GDBM_H
BUILTIN_FIND_HEADERS.GDBM_H=	gdbm.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.gdbm)
IS_BUILTIN.gdbm=	no
.  if empty(GDBM_H:M__nonexistent__)
IS_BUILTIN.gdbm=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.gdbm

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.gdbm) && \
    !empty(IS_BUILTIN.gdbm:M[yY][eE][sS])
BUILTIN_PKG.gdbm!=							\
	${AWK} '/\#define[ 	]*GDBM_VERSION_MAJOR/{major=$$3}	\
		/\#define[ 	]*GDBM_VERSION_MINOR/{minor=$$3}	\
		/\#define[ 	]*GDBM_VERSION_PATCH/{patch=$$3}	\
		/\#define[ 	]*GDBM_OPT_ILLEGAL/{illegal=$$3}	\
		END {							\
			if(major != "" && minor != "" && patch !="")	\
				printf("gdbm-%d.%d.%d", major, minor, patch); \
			else if ( illegal == "20" )			\
				print "gdbm-1.8.3";			\
			else						\
				print "gdbm-1.0"			\
		}							\
	' ${GDBM_H:Q}
.endif
MAKEVARS+=	BUILTIN_PKG.gdbm

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.gdbm)
.  if ${PREFER.gdbm} == "pkgsrc"
USE_BUILTIN.gdbm=	no
.  else
USE_BUILTIN.gdbm=	${IS_BUILTIN.gdbm}
.    if defined(BUILTIN_PKG.gdbm) && \
	!empty(IS_BUILTIN.gdbm:M[yY][eE][sS])
USE_BUILTIN.gdbm=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.gdbm}
.        if !empty(USE_BUILTIN.gdbm:M[yY][eE][sS])
USE_BUILTIN.gdbm!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.gdbm:Q}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.gdbm
