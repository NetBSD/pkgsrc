# $NetBSD: builtin.mk,v 1.36 2013/11/23 12:10:13 obache Exp $

BUILTIN_PKG:=	openssl

BUILTIN_FIND_LIBS:=		crypto des ssl
BUILTIN_FIND_HEADERS_VAR:=	H_OPENSSLCONF H_OPENSSLV
BUILTIN_FIND_HEADERS.H_OPENSSLCONF=	openssl/opensslconf.h
BUILTIN_FIND_HEADERS.H_OPENSSLV=	openssl/opensslv.h 

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.openssl)
IS_BUILTIN.openssl=	no
.  if empty(H_OPENSSLV:M__nonexistent__) && empty(H_OPENSSLV:M${LOCALBASE}/*)
IS_BUILTIN.openssl=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.openssl

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.openssl) && \
    !empty(IS_BUILTIN.openssl:M[yY][eE][sS]) && \
    empty(H_OPENSSLV:M__nonexistent__)
BUILTIN_VERSION.openssl!=						\
	${AWK} 'BEGIN { hex="0123456789abcdef";				\
			alpha="abcdefghijklmnopqrstuvwxyz";	\
		}							\
		/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			major = index(hex, substr($$3, 3, 1)) - 1;	\
			i = 16 * (index(hex, substr($$3, 4, 1)) - 1);	\
			i += index(hex, substr($$3, 5, 1)) - 1;		\
			minor = "."i;					\
			i = 16 * (index(hex, substr($$3, 6, 1)) - 1);	\
			i += index(hex, substr($$3, 7, 1)) - 1;		\
			teeny = "."i;					\
			i = 16 * (index(hex, substr($$3, 8, 1)) - 1);	\
			i += index(hex, substr($$3, 9, 1)) - 1;		\
			if (i == 0) {					\
				patchlevel = "";			\
			} else if (i > 26) {				\
				patchlevel = "a";			\
			} else {					\
				patchlevel = substr(alpha,i,1);			\
			}						\
			printf "%s%s%s%s\n",				\
				major, minor, teeny, patchlevel;	\
			exit 0;						\
		}							\
	' ${H_OPENSSLV}

.  if !empty(BUILTIN_VERSION.openssl:M0\.9\.6g) && \
      empty(H_OPENSSLV:M__nonexistent__)
#
# If the native OpenSSL contains the security fixes pulled up to the
# netbsd-1-6 branch on 2003-11-07, then pretend it's openssl-0.9.6l.
#
BUILTIN_OPENSSL_HAS_20031107_FIX!=					\
	${AWK} 'BEGIN { ans = "no" }					\
		/OPENSSL_HAS_20031107_FIX/ { ans = "yes" }		\
		END { print ans; exit 0 }				\
	' ${H_OPENSSLV}
.    if !empty(BUILTIN_OPENSSL_HAS_20031107_FIX:M[yY][eE][sS])
BUILTIN_VERSION.openssl=	0.9.6l
.    endif
#
# If the native OpenSSL contains the security fixes pulled up to the
# netbsd-1-6 branch on 2004-04-01, then pretend it's openssl-0.9.6m.
#
BUILTIN_OPENSSL_HAS_20040401_FIX!=					\
	${AWK} 'BEGIN { ans = "no" }					\
		/OPENSSL_HAS_20040401_FIX/ { ans = "yes" }		\
		END { print ans; exit 0 }				\
	' ${H_OPENSSLV}
.    if !empty(BUILTIN_OPENSSL_HAS_20040401_FIX:M[yY][eE][sS])
BUILTIN_VERSION.openssl=	0.9.6m
.    endif
.  elif !empty(BUILTIN_VERSION.openssl:M0\.9\.7d) && \
        empty(H_OPENSSLV:M__nonexistent__)
#
# If the native OpenSSL contains the security fixes pulled up to the
# netbsd-2-0, netbsd-2, and netbsd-3-0 branches on 2005-10-11, then
# pretend it's openssl-0.9.7h.
#
BUILTIN_OPENSSL_HAS_20051011_FIX!=					\
	${AWK} 'BEGIN { ans = "no" }					\
		/OPENSSL_HAS_20051011_FIX/ { ans = "yes" }		\
		END { print ans; exit 0 }				\
	' ${H_OPENSSLV}
.    if !empty(BUILTIN_OPENSSL_HAS_20051011_FIX:M[yY][eE][sS])
BUILTIN_VERSION.openssl=	0.9.7h
.    endif
.  endif
BUILTIN_PKG.openssl=	openssl-${BUILTIN_VERSION.openssl}
.endif
MAKEVARS+=	BUILTIN_PKG.openssl
MAKEVARS+=	BUILTIN_VERSION.openssl

.if !defined(BUILTIN_OPENSSL_HAS_THREADS) && \
    !empty(IS_BUILTIN.openssl:M[yY][eE][sS]) && \
    empty(H_OPENSSLCONF:M__nonexistent__)
BUILTIN_OPENSSL_HAS_THREADS!=						\
	${AWK} 'BEGIN { ans = "no" }					\
		/\#[ 	]*define[ 	]*OPENSSL_THREADS/ { ans= "yes" } \
		/\#[ 	]*define[ 	]*THREADS/ { ans = "yes" }	\
		END { print ans; exit 0 }				\
	' ${H_OPENSSLCONF:Q}
.endif
MAKEVARS+=	BUILTIN_OPENSSL_HAS_THREADS

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.openssl)
.  if ${PREFER.openssl} == "pkgsrc"
USE_BUILTIN.openssl=	no
.  else
USE_BUILTIN.openssl=	${IS_BUILTIN.openssl}
.    if defined(BUILTIN_PKG.openssl) && \
        !empty(IS_BUILTIN.openssl:M[yY][eE][sS])
USE_BUILTIN.openssl=	yes
.      for dep_ in ${BUILDLINK_API_DEPENDS.openssl}
.        if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
USE_BUILTIN.openssl!=							\
	if ${PKG_ADMIN} pmatch ${dep_:Q} ${BUILTIN_PKG.openssl:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.    if !empty(IS_BUILTIN.openssl:M[yY][eE][sS]) && \
	defined(USE_FEATURES.openssl)
.      if !empty(USE_FEATURES.openssl:Mthreads) && \
	  !empty(BUILTIN_OPENSSL_HAS_THREADS:M[nN][oO])
USE_BUILTIN.openssl=	no
.      endif
.    endif
.  endif  # PREFER.openssl
.endif
MAKEVARS+=	USE_BUILTIN.openssl

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.openssl?=	no
.if !empty(CHECK_BUILTIN.openssl:M[nN][oO])

.  if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
.    if empty(H_OPENSSLV:M__nonexistent__)
.      if !empty(H_OPENSSLV:M/usr/sfw/*)
BUILDLINK_PREFIX.openssl=	/usr/sfw
BUILDLINK_PASSTHRU_DIRS+=	/usr/sfw
.      elif !empty(H_OPENSSLV:M/usr/*)
BUILDLINK_PREFIX.openssl=	/usr
.      elif !empty(H_OPENSSLV:M/boot/common/*)
BUILDLINK_PREFIX.openssl=	/boot/common
.      endif
.    endif
.  endif

# By default, we don't bother with the old DES API.
USE_OLD_DES_API?=	no
.  if !empty(USE_OLD_DES_API:M[yY][eE][sS])
#
# If we're using the old DES API, then check to see if the old DES
# code was factored out into a separate library and header files and
# no longer a part of libcrypto.
#
.    if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
.      if exists(${BUILDLINK_PREFIX.openssl}/include/des.h) && \
          !empty(BUILTIN_LIB_FOUND.des:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=	l:crypto:des:crypto
WRAPPER_REORDER_CMDS+=	reorder:l:des:crypto
.      endif
.    endif

# The idea is to avoid the need to patch source files for packages that
# use OpenSSL for DES support by ensuring that including <openssl/des.h>
# will always present the old DES API.
#
# (1) If des_old.h exists, then we're using OpenSSL>=0.9.7, and
#     <openssl/des.h> already does the right thing.
#
# (2) If des_old.h doesn't exist, then one of two things is happening:
#     (a) If <openssl/des.h> is old and (only) supports the old DES API,
#         then <openssl/des.h> does the right thing.
#     (b) If it's NetBSD's Special(TM) one that stripped out the old DES
#         support into a separate library and header (-ldes, <des.h>),
#         then we create a new header <openssl/des.h> that includes the
#         system one and <des.h>, and we create an <openssl/des_old.h>
#         that just includes <des.h>.
#
BUILDLINK_TARGETS+=	buildlink-openssl-des-h
.    if !target(buildlink-openssl-des-h)
.PHONY: buildlink-openssl-des-h
buildlink-openssl-des-h:
	${RUN}								\
	bl_odes_h="${BUILDLINK_DIR}/include/openssl/des.h";		\
	bl_odes_old_h="${BUILDLINK_DIR}/include/openssl/des_old.h";	\
	odes_h="${BUILDLINK_PREFIX.openssl}/include/openssl/des.h";	\
	odes_old_h="${BUILDLINK_PREFIX.openssl}/include/openssl/des_old.h"; \
	des_h="${BUILDLINK_PREFIX.openssl}/include/des.h";		\
	if ${TEST} -f "$$odes_old_h"; then				\
		${ECHO_BUILDLINK_MSG} "<openssl/des.h> supports old DES API."; \
		exit 0;							\
	elif ${GREP} -q "des_cblock" "$$odes_h" 2>/dev/null; then	\
		${ECHO_BUILDLINK_MSG} "<openssl/des.h> supports old DES API."; \
		exit 0;							\
	elif ${TEST} -f "$$des_h" -a -f "$$odes_h"; then		\
		${ECHO_BUILDLINK_MSG} "Creating $$bl_odes_h";		\
		${RM} -f $$bl_odes_h;					\
		${MKDIR} `${DIRNAME} $$bl_odes_h`;			\
		( ${ECHO} "/* Created by openssl/builtin.mk:${.TARGET} */"; \
		  ${ECHO} "#include \"$$odes_h\"";			\
		  ${ECHO} "#include \"$$des_h\"";			\
		) > $$bl_odes_h;					\
		${ECHO_BUILDLINK_MSG} "Creating $$bl_odes_old_h";	\
		${RM} -f $$bl_odes_old_h;				\
		${MKDIR} `${DIRNAME} $$bl_odes_old_h`;			\
		( ${ECHO} "/* Created by openssl/builtin.mk:${.TARGET} */"; \
		  ${ECHO} "#include \"$$des_h\"";			\
		) > $$bl_odes_old_h;					\
		exit 0;							\
	else								\
		${ECHO} "Unable to find headers for old DES API.";	\
		exit 1;							\
	fi
.    endif
.  endif  # USE_OLD_DES_API == yes

.  if defined(PKG_SYSCONFDIR.openssl)
SSLDIR=	${PKG_SYSCONFDIR.openssl}
.  elif !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
.    if ${OPSYS} == "NetBSD"
SSLDIR=	/etc/openssl
.    elif ${OPSYS} == "Haiku"
SSLDIR=	/boot/common/ssl
.    else
SSLDIR=	/etc/ssl 		# most likely place
.    endif
.  else
SSLDIR=	${PKG_SYSCONFBASEDIR}/openssl
.  endif

SSLCERTS=	${SSLDIR}/certs
SSLKEYS=	${SSLDIR}/private

BUILD_DEFS+=	SSLDIR SSLCERTS SSLKEYS

# create pc files for builtin version; other versions assumed to contain them
# If we are using the builtin version, check whether it has a *.pc
# files or not.  If the latter, generate fake ones.
.  if !empty(USE_BUILTIN.openssl:M[Yy][Ee][Ss])
BUILDLINK_TARGETS+=	openssl-fake-pc

.    if !defined(HAS_OPENSSL_FAKE_PC)
HAS_OPENSSL_FAKE_PC=

openssl-fake-pc:
	${RUN} \
	src=${BUILDLINK_PREFIX.openssl}/lib${LIBABISUFFIX}/pkgconfig/libcrypto.pc; \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/libcrypto.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		{ ${ECHO} 'prefix=${BUILDLINK_PREFIX.openssl}'; \
		${ECHO} 'exec_prefix=$${prefix}'; \
		${ECHO} 'libdir=$${exec_prefix}/lib${LIBABISUFFIX}'; \
		${ECHO} 'includedir=$${prefix}/include'; \
		${ECHO}; \
		${ECHO} 'Name: OpenSSL-libcrypto'; \
		${ECHO} 'Description: OpenSSL cryptography library'; \
		${ECHO} 'Version: ${BUILTIN_VERSION.openssl}'; \
		${ECHO} 'Libs: -L$${libdir} -lcrypto'; \
		${ECHO} 'Cflags: -I$${includedir}'; \
		} >$${dst}; \
	fi
	${RUN} \
	src=${BUILDLINK_PREFIX.openssl}/lib${LIBABISUFFIX}/pkgconfig/libssl.pc; \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/libssl.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		{ ${ECHO} 'prefix=${BUILDLINK_PREFIX.openssl}'; \
		${ECHO} 'exec_prefix=$${prefix}'; \
		${ECHO} 'libdir=$${exec_prefix}/lib${LIBABISUFFIX}'; \
		${ECHO} 'includedir=$${prefix}/include'; \
		${ECHO}; \
		${ECHO} 'Name: OpenSSL'; \
		${ECHO} 'Description: Secure Sockets Layer and cryptography libraries'; \
		${ECHO} 'Version: ${BUILTIN_VERSION.openssl}'; \
		${ECHO} 'Libs: -L$${libdir} -lssl -lcrypto'; \
		${ECHO} 'Cflags: -I$${includedir}'; \
		} >$${dst}; \
	fi
	${RUN} \
	src=${BUILDLINK_PREFIX.openssl}/lib${LIBABISUFFIX}/pkgconfig/openssl.pc; \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/openssl.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		{ ${ECHO} 'prefix=${BUILDLINK_PREFIX.openssl}'; \
		${ECHO} 'exec_prefix=$${prefix}'; \
		${ECHO} 'libdir=$${exec_prefix}/lib${LIBABISUFFIX}'; \
		${ECHO} 'includedir=$${prefix}/include'; \
		${ECHO}; \
		${ECHO} 'Name: OpenSSL'; \
		${ECHO} 'Description: Secure Sockets Layer and cryptography libraries and tools'; \
		${ECHO} 'Version: ${BUILTIN_VERSION.openssl}'; \
		${ECHO} 'Libs: -L$${libdir} -lssl -lcrypto'; \
		${ECHO} 'Cflags: -I$${includedir}'; \
		} >$${dst}; \
	fi
.    endif
.  endif

.endif	# CHECK_BUILTIN.openssl
