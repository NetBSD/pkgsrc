# $NetBSD: builtin.mk,v 1.50 2023/01/12 11:01:41 markd Exp $

BUILTIN_PKG:=	openssl

BUILTIN_FIND_LIBS:=			crypto ssl
BUILTIN_FIND_HEADERS_VAR:=		H_OPENSSLCONF H_OPENSSLV
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
MAKEVARS+=		IS_BUILTIN.openssl

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.openssl) && \
    ${IS_BUILTIN.openssl:M[yY][eE][sS]} && \
    empty(H_OPENSSLV:M__nonexistent__)
BUILTIN_VERSION.openssl!=						\
	${AWK} 'BEGIN { hex="0123456789abcdef";				\
			alpha="abcdefghijklmnopqrstuvwxyz";	\
		}							\
		/\#[ 	]+define/ { sub("\#[ \\t]+define", "\#define", $$0); } \
		/\#define[ 	]*OPENSSL_VERSION_STR/ {		\
			printf "%s\n",substr($$3,2,length($$3)-2);	\
			exit 0;						\
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
				patchlevel = substr(alpha,i,1);		\
			}						\
			printf "%s%s%s%s\n",				\
				major, minor, teeny, patchlevel;	\
			exit 0;						\
		}							\
	' ${H_OPENSSLV}
BUILTIN_PKG.openssl=	openssl-${BUILTIN_VERSION.openssl}
.endif
MAKEVARS+=		BUILTIN_PKG.openssl
MAKEVARS+=		BUILTIN_VERSION.openssl

.if !defined(BUILTIN_OPENSSL_HAS_THREADS) && \
    ${IS_BUILTIN.openssl:M[yY][eE][sS]} && \
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
USE_BUILTIN.openssl=		no
.  else
USE_BUILTIN.openssl=		${IS_BUILTIN.openssl}
.    if defined(BUILTIN_PKG.openssl) && \
        ${IS_BUILTIN.openssl:M[yY][eE][sS]}
USE_BUILTIN.openssl=		yes
### take care builtin check case, BUILDLINK_API_DEPENDS may not be defined yet.
CHECK_BUILTIN.openssl?=		no
.      if ${CHECK_BUILTIN.openssl:M[yY][eE][sS]}
BUILDLINK_API_DEPENDS.openssl?=	openssl>=1.1.1
.      endif
.      for dep_ in ${BUILDLINK_API_DEPENDS.openssl}
.        if ${USE_BUILTIN.openssl:M[yY][eE][sS]}
USE_BUILTIN.openssl!=							\
	if ${PKG_ADMIN} pmatch ${dep_:Q} ${BUILTIN_PKG.openssl:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.    if ${IS_BUILTIN.openssl:M[yY][eE][sS]} && \
	defined(USE_FEATURES.openssl)
.      if !empty(USE_FEATURES.openssl:Mthreads) && \
	  !empty(BUILTIN_OPENSSL_HAS_THREADS:M[nN][oO])
USE_BUILTIN.openssl=		no
.      endif
.    endif
.  endif  # PREFER.openssl
.endif
MAKEVARS+=			USE_BUILTIN.openssl

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.openssl?=	no
.if ${CHECK_BUILTIN.openssl:M[nN][oO]}

.  if ${USE_BUILTIN.openssl:M[yY][eE][sS]}
.    if empty(H_OPENSSLV:M__nonexistent__)
.      if !empty(H_OPENSSLV:M/usr/sfw/*)
BUILDLINK_PREFIX.openssl=	/usr/sfw
BUILDLINK_PASSTHRU_DIRS+=	/usr/sfw
.      elif !empty(H_OPENSSLV:M/usr/*)
BUILDLINK_PREFIX.openssl=	/usr
.      elif !empty(H_OPENSSLV:M/boot/system/develop/*)
BUILDLINK_PREFIX.openssl=	/boot/system/develop
.      elif !empty(H_OPENSSLV:M/boot/common/*)
BUILDLINK_PREFIX.openssl=	/boot/common
.      endif
.    endif
.  endif

.  if defined(PKG_SYSCONFDIR.openssl)
SSLDIR=	${PKG_SYSCONFDIR.openssl}
.  elif ${USE_BUILTIN.openssl:M[yY][eE][sS]}
.    if ${OPSYS} == "NetBSD"
SSLDIR=	/etc/openssl
.    elif ${OPSYS} == "Linux"
.      if exists(/etc/pki/tls)
# Some distributions have moved to /etc/pki/tls, with incomplete
# symlinks from /etc/ssl.  Prefer the new location if it exists
SSLDIR=	/etc/pki/tls
.      else
SSLDIR=	/etc/ssl 		# standard location
.      endif
.    elif ${OPSYS} == "Haiku"
.      if exists(/boot/system/data/ssl)
SSLDIR=	/boot/system/data/ssl
.      else
SSLDIR=	/boot/common/data/ssl
.      endif
.    else
SSLDIR=	/etc/ssl 		# most likely place
.    endif
.  else
SSLDIR=	${PKG_SYSCONFBASEDIR}/openssl
.  endif

SSLCERTS=	${SSLDIR}/certs
# Some systems use CA bundles instead of files and hashed symlinks.
# Continue to define SSLCERTS because it's unclear if that's the
# directory that has one file per cert, or the directory that contains
# trust anchor config in some fortm.
.  if exists(${SSLDIR}/certs/ca-bundle.crt)
SSLCERTBUNDLE=	${SSLDIR}/certs/ca-bundle.crt
.  endif
SSLKEYS=	${SSLDIR}/private

BUILD_DEFS+=	SSLDIR SSLCERTS SSLCERTBUNDLE SSLKEYS

# create pc files for builtin version; other versions assumed to contain them
# If we are using the builtin version, check whether it has a *.pc
# files or not.  If the latter, generate fake ones.
.  if ${USE_BUILTIN.openssl:M[Yy][Ee][Ss]}
BUILDLINK_TARGETS+=	openssl-fake-pc

.    if !defined(HAS_OPENSSL_FAKE_PC)
HAS_OPENSSL_FAKE_PC=

.PHONY: openssl-fake-pc
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
