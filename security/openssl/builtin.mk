# $NetBSD: builtin.mk,v 1.14 2005/06/09 06:07:29 jlam Exp $

BUILTIN_PKG:=	openssl

BUILTIN_FIND_LIBS:=		des
BUILTIN_FIND_FILES_VAR:=	H_OPENSSL
BUILTIN_FIND_FILES.H_OPENSSL=	/usr/include/openssl/opensslv.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.openssl)
IS_BUILTIN.openssl=	no
.  if empty(H_OPENSSL:M${LOCALBASE}/*) && exists(${H_OPENSSL})
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
    exists (${H_OPENSSL})
BUILTIN_VERSION.openssl!=						\
	${AWK} 'BEGIN { hex="0123456789abcdef";				\
			split("abcdefghijklmnopqrstuvwxyz", alpha, "");	\
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
				patchlevel = alpha[i];			\
			}						\
			printf "%s%s%s%s\n",				\
				major, minor, teeny, patchlevel;	\
			exit 0;						\
		}							\
	' ${H_OPENSSL}

.  if !empty(BUILTIN_VERSION.openssl:M0\.9\.6g) && \
      exists(${H_OPENSSL})
#
# If the native OpenSSL contains the security fixes pulled up to the
# netbsd-1-6 branch on 2003-11-07, then pretend it's openssl-0.9.6l.
#    
BUILTIN_OPENSSL_HAS_20031107_FIX!=					\
	${AWK} 'BEGIN { ans = "no" }					\
		/OPENSSL_HAS_20031107_FIX/ { ans = "yes" }		\
		END { print ans; exit 0 }				\
	' ${H_OPENSSL}
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
	' ${H_OPENSSL}
.    if !empty(BUILTIN_OPENSSL_HAS_20040401_FIX:M[yY][eE][sS])
BUILTIN_VERSION.openssl=	-0.9.6m
.    endif
.  endif
BUILTIN_PKG.openssl=	openssl-${BUILTIN_VERSION.openssl}
.endif
MAKEVARS+=	BUILTIN_PKG.openssl

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
.      for _dep_ in ${BUILDLINK_DEPENDS.openssl}
.        if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
USE_BUILTIN.openssl!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.openssl:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
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
BUILDLINK_PREFIX.openssl=	/usr
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
#         system one and <des.h>.
#
BUILDLINK_TARGETS+=	buildlink-openssl-des-h
.    if !target(buildlink-openssl-des-h)
.PHONY: buildlink-openssl-des-h
buildlink-openssl-des-h:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	bl_odes_h="${BUILDLINK_DIR}/include/openssl/des.h";		\
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
		exit 0;							\
	else								\
		${ECHO} "Unable to find headers for old DES API.";	\
		exit 1;							\
	fi
.    endif
.  endif  # USE_OLD_DES_API == yes

.  if defined(PKG_SYSCONFDIR.openssl)
SSLCERTS=	${PKG_SYSCONFDIR.openssl}/certs
SSLKEYS=	${PKG_SYSCONFDIR.openssl}/private
.  elif ${OPSYS} == "NetBSD"
SSLCERTS=	/etc/openssl/certs
SSLKEYS=	/etc/openssl/private
.  elif !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
SSLCERTS=	/etc/ssl/certs		# likely place where certs live
SSLKEYS=	/etc/ssl/private	# likely place where private keys live
.  else
SSLCERTS=	${PKG_SYSCONFBASEDIR}/openssl/certs
SSLKEYS=	${PKG_SYSCONFBASEDIR}/openssl/private
.  endif
BUILD_DEFS+=	SSLCERTS SSLKEYS

.endif	# CHECK_BUILTIN.openssl
