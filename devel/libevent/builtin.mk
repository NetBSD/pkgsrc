# $NetBSD: builtin.mk,v 1.21 2020/11/06 15:48:15 ryoon Exp $

BUILTIN_PKG:=	libevent

BUILTIN_FIND_HEADERS_VAR:=		H_LIBEVENT H_LIBEVENTCONFIG
BUILTIN_FIND_HEADERS.H_LIBEVENT=	event.h
BUILTIN_FIND_HEADERS.H_LIBEVENTCONFIG=	event-config.h event2/event-config.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libevent)
IS_BUILTIN.libevent=	no
.  if empty(H_LIBEVENT:M__nonexistent__) && empty(H_LIBEVENT:M${LOCALBASE}/*)
IS_BUILTIN.libevent=	yes
.  endif
.endif	# IS_BUILTIN.libevent
MAKEVARS+=		IS_BUILTIN.libevent

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libevent) && \
    !empty(IS_BUILTIN.libevent:M[yY][eE][sS]) && \
    empty(H_LIBEVENT:M__nonexistent__)
.  if empty(H_LIBEVENTCONFIG:M__nonexistent__)
_BLTN_EVENT_1_4_11!=		\
	${GREP} -c 1.4.11-stable ${H_LIBEVENTCONFIG} || ${TRUE}
_BLTN_EVENT_1_4_12!=		\
	${GREP} -c 1.4.12-stable ${H_LIBEVENTCONFIG} || ${TRUE}
_BLTN_EVENT_2_0_21!=		\
	${GREP} -c 2.0.21-stable ${H_LIBEVENTCONFIG} || ${TRUE}
_BLTN_EVENT_2_0_22!=		\
	${GREP} -c 2.0.22-stable ${H_LIBEVENTCONFIG} || ${TRUE}
.    if ${_BLTN_EVENT_2_0_22} == "1"
BUILTIN_VERSION.libevent=	2.0.22
.    elif ${_BLTN_EVENT_2_0_21} == "1"
BUILTIN_VERSION.libevent=	2.0.21
.    elif ${_BLTN_EVENT_1_4_12} == "1"
BUILTIN_VERSION.libevent=	1.4.12
.    elif ${_BLTN_EVENT_1_4_11} == "1"
BUILTIN_VERSION.libevent=	1.4.11
.    else
BUILTIN_VERSION.libevent=	1.4.4
.    endif
.  else
# libevent>=1.3: bufferevent_base_set added
_BLTN_EVENT_13!=		\
	${GREP} -c bufferevent_base_set ${H_LIBEVENT} || ${TRUE}
# libevent>=1.2: evtag_*, event_base_free added
_BLTN_EVENT_12!=		\
	${GREP} -c evtag_ ${H_LIBEVENT} || ${TRUE}
# libevent>=1.1b: evbuffer_add_vprintf added
_BLTN_EVENT_11b!=		\
	${GREP} -c evbuffer_add_vprintf ${H_LIBEVENT} || ${TRUE}
# libevent>=1.0d: evbuffer_readline added
_BLTN_EVENT_10d!=		\
	${GREP} -c event_base_loopexit ${H_LIBEVENT} || ${TRUE}
# libevent>=1.0c: event_set_log_callback, event_base_loopexit and
#                 event_get_{version,method} added
_BLTN_EVENT_10c!=		\
	${GREP} -c event_base_loopexit ${H_LIBEVENT} || ${TRUE}
# libevent>=1.0: event_base_* and event_priority_* added
_BLTN_EVENT_10!=		\
	${GREP} -c event_base_ ${H_LIBEVENT} || ${TRUE}
# libevent>=0.9: evbuffer_{expand,remove} added
_BLTN_EVENT_09!=		\
	${GREP} -c evbuffer_expand ${H_LIBEVENT} || ${TRUE}
# libevent>=0.8: buffering functions added
_BLTN_EVENT_08!=		\
	${GREP} -c evbuffer ${H_LIBEVENT} || ${TRUE}
# libevent>=0.7b: WIN32 support added
_BLTN_EVENT_07b!=		\
	${GREP} -c WIN32 ${H_LIBEVENT} || ${TRUE}
# libevent>=0.6: evtimer_* added
_BLTN_EVENT_06!=		\
	${GREP} -c evtimer_ ${H_LIBEVENT} || ${TRUE}

.    if ${_BLTN_EVENT_13} == "1"
BUILTIN_VERSION.libevent=	1.3
.    elif ${_BLTN_EVENT_12} == "1"
BUILTIN_VERSION.libevent=	1.2
.    elif ${_BLTN_EVENT_11b} == "1"
BUILTIN_VERSION.libevent=	1.1b
.    elif ${_BLTN_EVENT_10d} == "1"
BUILTIN_VERSION.libevent=	1.0d
.    elif ${_BLTN_EVENT_10c} == "1"
BUILTIN_VERSION.libevent=	1.0c
.    elif ${_BLTN_EVENT_10} == "1"
BUILTIN_VERSION.libevent=	1.0
.    elif ${_BLTN_EVENT_09} == "1"
BUILTIN_VERSION.libevent=	0.9
.    elif ${_BLTN_EVENT_08} == "1"
BUILTIN_VERSION.libevent=	0.8
.    elif ${_BLTN_EVENT_07b} == "1"
BUILTIN_VERSION.libevent=	0.7b
.    elif ${_BLTN_EVENT_06} == "1"
BUILTIN_VERSION.libevent=	0.6
.    else
BUILTIN_VERSION.libevent=	0.5
.    endif
.  endif
BUILTIN_PKG.libevent=		libevent-${BUILTIN_VERSION.libevent}
.endif
MAKEVARS+=			BUILTIN_PKG.libevent

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libevent)
.  if ${PREFER.libevent} == "pkgsrc"
USE_BUILTIN.libevent=	no
.  else
USE_BUILTIN.libevent=	${IS_BUILTIN.libevent}
.    if defined(BUILTIN_PKG.libevent) && \
        !empty(IS_BUILTIN.libevent:M[yY][eE][sS])
USE_BUILTIN.libevent=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libevent}
.        if !empty(USE_BUILTIN.libevent:M[yY][eE][sS])
USE_BUILTIN.libevent!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libevent:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libevent
.endif
MAKEVARS+=		USE_BUILTIN.libevent

# Fake pkg-config for builtin libevent on NetBSD

.if !empty(USE_BUILTIN.libevent:M[yY][eE][sS])
.  if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-libevent-pkgconfig

BLKDIR_PKGCFG=			${BUILDLINK_DIR}/lib/pkgconfig
LIBEVENT_PKGCFGF=		libevent.pc
LIBEVENT_OPENSSL_PKGCFGF=	libevent_openssl.pc
LIBEVENT_PTHREADS_PKGCFGF=	libevent_pthreads.pc
LIBEVENT_PREFIX=		${BUILDLINK_PREFIX.libevent}

override-libevent-pkgconfig: override-message-libevent-pkgconfig
override-message-libevent-pkgconfig:
	@${STEP_MSG} "Generating pkg-config files for builtin libevent package."

override-libevent-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	${RM} -f ${BLKDIR_PKGCFG}/${LIBEVENT_PKGCFGF};	\
	{						\
	${ECHO} "prefix=${LIBEVENT_PREFIX}";		\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO} "";					\
	${ECHO} "Name: libevent";			\
	${ECHO} "Description: libevent is an asynchronous notification event loop library"; \
	${ECHO} "Version: ${BUILTIN_VERSION.libevent}";	\
	${ECHO} "Libs: ${COMPILER_RPATH_FLAG}\$${libdir} -L\$${libdir} -levent";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} > ${BLKDIR_PKGCFG}/${LIBEVENT_PKGCFGF};
	${RUN}						\
	${RM} -f ${BLKDIR_PKGCFG}/${LIBEVENT_OPENSSL_PKGCFGF};	\
	{						\
	${ECHO} "prefix=${LIBEVENT_PREFIX}";		\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO} "";					\
	${ECHO} "Name: libevent_openssl";			\
	${ECHO} "Description: libevent_openssl adds openssl-based TLS support to libevent"; \
	${ECHO} "Version: ${BUILTIN_VERSION.libevent}";	\
	${ECHO} "Requires: libevent";	\
	${ECHO} "Libs: ${COMPILER_RPATH_FLAG}\$${libdir} -L\$${libdir} -levent_openssl";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} > ${BLKDIR_PKGCFG}/${LIBEVENT_OPENSSL_PKGCFGF};
	${RUN}						\
	${RM} -f ${BLKDIR_PKGCFG}/${LIBEVENT_PTHREADS_PKGCFGF};	\
	{						\
	${ECHO} "prefix=${LIBEVENT_PREFIX}";		\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO} "";					\
	${ECHO} "Name: libevent_pthreads";			\
	${ECHO} "Description: libevent_pthreads adds pthreads-based threading support to libevent"; \
	${ECHO} "Version: ${BUILTIN_VERSION.libevent}";	\
	${ECHO} "Requires: libevent";	\
	${ECHO} "Libs: ${COMPILER_RPATH_FLAG}\$${libdir} -L\$${libdir} -levent_pthreads";	\
	${ECHO} "Cflags: -I\$${includedir} -pthread";		\
	} > ${BLKDIR_PKGCFG}/${LIBEVENT_PTHREADS_PKGCFGF};
.  endif
.endif
