# $NetBSD: db1.builtin.mk,v 1.7 2004/11/28 05:44:34 jlam Exp $

.for _lib_ in db db1
.  if !defined(_BLNK_LIB_FOUND.${_lib_})
_BLNK_LIB_FOUND.${_lib_}!=	\
	if ${TEST} "`${ECHO} /usr/lib/lib${_lib_}.*`" != "/usr/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	elif ${TEST} "`${ECHO} /lib/lib${_lib_}.*`" != "/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIB_FOUND.${_lib_}
.  endif
.endfor
.undef _lib_

.if !defined(IS_BUILTIN.db1)
IS_BUILTIN.db1=		no
#
# The builtin Berkeley database library must support hash version 2 or
# else it doesn't support db-1.85 databases.
#
_BLNK_NATIVE_DB1_OK=	no
.  for _inc_ in /usr/include/db.h /usr/include/db1/db.h
.    if exists(${_inc_})
_BLNK_NATIVE_DB1_OK.${_inc_}!=	\
	if ${GREP} -q "^\#define.*HASHVERSION.*2$$" ${_inc_}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    endif
_BLNK_NATIVE_DB1_OK+=	${_BLNK_NATIVE_DB1_OK.${_inc_}}
.  endfor
.  undef _inc_
.  if !empty(_BLNK_NATIVE_DB1_OK:M[yY][eE][sS])
IS_BUILTIN.db1=		yes
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.db1
.endif	# IS_BUILTIN.db1

.if !defined(USE_BUILTIN.db1)
USE_BUILTIN.db1?=	${IS_BUILTIN.db1}
_INCOMPAT_DB1?=		# empty
.  for _pattern_ in ${_INCOMPAT_DB1} ${INCOMPAT_DB1}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.db1=	no
.    endif
.  endfor
.  undef _pattern_
BUILDLINK_VARS+=	USE_BUILTIN.db1
.endif	# USE_BUILTIN.db1

CHECK_BUILTIN.db1?=	no
.if !empty(CHECK_BUILTIN.db1:M[nN][oO])
.  if !empty(USE_BUILTIN.db1:M[yY][eE][sS])
BUILDLINK_PREFIX.db1=	/usr
.    if exists(/usr/include/db.h)
BUILDLINK_INCDIRS.db1=	include
.    elif exists(/usr/include/db1/db.h)
BUILDLINK_INCDIRS.db1=	include/db1
.    endif
.    if !empty(_BLNK_LIB_FOUND.db:M[yY][eE][sS])
BUILDLINK_LDADD.db1=	-ldb
.    elif !empty(_BLNK_LIB_FOUND.db1:M[yY][eE][sS])
BUILDLINK_LDADD.db1=	-ldb1
BUILDLINK_TRANSFORM+=	l:db:db1
.    else
BUILDLINK_LDADD.db1=	# empty
BUILDLINK_TRANSFORM+=	rm:-ldb
.    endif
BUILDLINK_LIBS.db1=	${BUILDLINK_LDADD.db1}

BUILDLINK_TARGETS+=	buildlink-db1-db185-h
.    if !target(buildlink-db1-db185-h)
.PHONY: buildlink-db1-db185-h
buildlink-db1-db185-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "#include <db.h>" > ${BUILDLINK_DIR}/include/db_185.h
.    endif

.  endif # USE_BUILTIN.db1 == yes
.endif	# CHECK_BUILTIN.db1
