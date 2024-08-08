# $NetBSD: builtin.mk,v 1.21 2024/08/08 08:27:53 wiz Exp $

BUILTIN_PKG:=	heimdal

BUILTIN_FIND_HEADERS_VAR:=		H_HEIMDAL
BUILTIN_FIND_HEADERS.H_HEIMDAL=		krb5/krb5.h krb5.h
BUILTIN_FIND_GREP.H_HEIMDAL=		heimdal_version
BUILTIN_FIND_FILES_VAR:=		SH_KRB5_CONFIG
BUILTIN_FIND_FILES.SH_KRB5_CONFIG=	/usr/bin/krb5-config
BUILTIN_FIND_GREP.SH_KRB5_CONFIG=	^[ 	]*--version)

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.heimdal)
IS_BUILTIN.heimdal=	no
.  if empty(H_HEIMDAL:M__nonexistent__) && empty(H_HEIMDAL:M${LOCALBASE}/*)
IS_BUILTIN.heimdal=	yes
.  endif
# heimdal in NetBSD<10 links against sqlite3, which might lead to linking
# against multiple versions of sqlite3.
# For that reason, do not accept that version as built-in.
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
IS_BUILTIN.heimdal=	no
.endif
.endif
MAKEVARS+=		IS_BUILTIN.heimdal

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.heimdal) && \
    ${IS_BUILTIN.heimdal:tl} == yes
.  if empty(SH_KRB5_CONFIG:M__nonexistent__)
BUILTIN_VERSION.heimdal!=						\
	${_CROSS_DESTDIR:U:Q}${SH_KRB5_CONFIG:Q} --version |		\
	${AWK} '{ print $$2; exit }'
.  else
BUILTIN_VERSION.heimdal?=	0.2t
.  endif
BUILTIN_PKG.heimdal=		heimdal-${BUILTIN_VERSION.heimdal}
.endif
MAKEVARS+=			BUILTIN_PKG.heimdal

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.heimdal)
.  if ${PREFER.heimdal} == "pkgsrc"
USE_BUILTIN.heimdal=	no
.  else
USE_BUILTIN.heimdal=	${IS_BUILTIN.heimdal}
.    if ${USE_BUILTIN.heimdal:tl} == yes
CHECK_BUILTIN.openssl:=	yes
.      include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=	no
.      if ${USE_BUILTIN.openssl:tl} == no
USE_BUILTIN.heimdal=	no
.      endif
.    endif
.    if defined(BUILTIN_PKG.heimdal) && \
       ${IS_BUILTIN.heimdal:tl} == yes
USE_BUILTIN.heimdal?=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.heimdal}
.        if ${USE_BUILTIN.heimdal:tl} == yes
USE_BUILTIN.heimdal!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.heimdal}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.heimdal
.endif
MAKEVARS+=	USE_BUILTIN.heimdal

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.heimdal?=	no
.if ${CHECK_BUILTIN.heimdal:tl} == no

.  if ${USE_BUILTIN.heimdal:tl} == no
BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.6

KRB5_CONFIG?=	${_CROSS_DESTDIR:U}${BUILDLINK_PREFIX.heimdal}/bin/krb5-config
CONFIGURE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
MAKE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
.  endif

.  if ${USE_BUILTIN.heimdal:tl} == yes
.    if !empty(SH_KRB5_CONFIG:M__nonexistent__)
BUILDLINK_TARGETS+=	fake-krb5-config

.PHONY: fake-krb5-config
fake-krb5-config:
	${RUN} \
	src=../../security/heimdal/files/krb5-config \
        dst=${BUILDLINK_DIR}/bin/krb5-config; \
	${SED} -e s/@HEIMDAL_VERSION@/${BUILTIN_VERSION.heimdal}/ \
	    $${src} >$${dst}; \
	${CHMOD} a+x $${dst}

KRB5_CONFIG?=	${BUILDLINK_DIR}/bin/krb5-config
.    else
KRB5_CONFIG?=	${_CROSS_DESTDIR:U}${SH_KRB5_CONFIG}
.    endif
CONFIGURE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
MAKE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
.  endif

.endif	# CHECK_BUILTIN.heimdal
