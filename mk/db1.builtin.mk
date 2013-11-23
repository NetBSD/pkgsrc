# $NetBSD: db1.builtin.mk,v 1.23 2013/11/23 09:10:14 obache Exp $

BUILTIN_PKG:=	db1

BUILTIN_FIND_LIBS:=		db1 db
BUILTIN_FIND_HEADERS_VAR:=	H_DB
BUILTIN_FIND_HEADERS.H_DB=	db1/db.h db.h
#
# The builtin Berkeley database library must support hash version 2 or
# else it doesn't support db-1.85 databases.
#
BUILTIN_FIND_GREP.H_DB=	^\#define.*HASHVERSION.*2$$

.include "buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.db1)
IS_BUILTIN.db1=	no
.  if empty(H_DB:M${LOCALBASE}/*) && exists(${H_DB})
IS_BUILTIN.db1=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.db1

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.db1)
# XXX
# XXX Until pkgsrc gets a databases/db1 package, we must always prefer the
# XXX native db1 package because the alternative doesn't yet exist.
# XXX
PREFER.db1=		native
.  if ${PREFER.db1} == "pkgsrc"
USE_BUILTIN.db1=	no
.  else
USE_BUILTIN.db1=	${IS_BUILTIN.db1}
.    if defined(BUILTIN_PKG.db1) && !empty(IS_BUILTIN.db1:M[yY][eE][sS])
USE_BUILTIN.db1=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.db1}
.        if !empty(USE_BUILTIN.db1:M[yY][eE][sS])
USE_BUILTIN.db1!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.db1:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.db1
.endif
MAKEVARS+=	USE_BUILTIN.db1

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.db1?=	no
.if !empty(CHECK_BUILTIN.db1:M[nN][oO])

.  if !empty(USE_BUILTIN.db1:M[yY][eE][sS])
BUILDLINK_PREFIX.db1=	/usr
.    if exists(${H_DB})
BUILDLINK_INCDIRS.db1?=	${H_DB:H:S/^${BUILDLINK_PREFIX.db1}\///}
.    endif
.    if !empty(BUILTIN_LIB_FOUND.db1:M[yY][eE][sS])
BUILDLINK_LDADD.db1=	-ldb1
BUILDLINK_TRANSFORM+=	l:db:db1
.    elif !empty(BUILTIN_LIB_FOUND.db:M[yY][eE][sS])
BUILDLINK_LDADD.db1=	-ldb
.    else
BUILDLINK_LDADD.db1=	# empty
.    endif
#BUILDLINK_LIBS.db1=	${BUILDLINK_LDADD.db1}
.  endif

BUILDLINK_TARGETS+=	buildlink-db1-db185-h
.  if !target(buildlink-db1-db185-h)
.PHONY: buildlink-db1-db185-h
buildlink-db1-db185-h:
	${RUN}								\
	src=${H_DB:Q};							\
	dest=${BUILDLINK_DIR:Q}"/include/db_185.h";			\
	if ${TEST} -f "$$src" -a ! -f "$$dest"; then			\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -fs "$$src" "$$dest";				\
	fi
.  endif

.endif	# CHECK_BUILTIN.db1
