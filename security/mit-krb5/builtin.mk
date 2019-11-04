# $NetBSD: builtin.mk,v 1.16 2019/11/04 21:12:55 rillig Exp $

BUILTIN_PKG:=	mit-krb5

.include "../../mk/bsd.fast.prefs.mk"

BUILTIN_FIND_HEADERS_VAR:=		H_MIT_KRB5
.if !(empty(MACHINE_PLATFORM:MDarwin-9.*-*) && \
      empty(MACHINE_PLATFORM:MDarwin-1?.*-*))
BUILTIN_FIND_HEADERS.H_MIT_KRB5=	krb5/krb5.h
.elif !empty(MACHINE_PLATFORM:MSunOS-*-*)
BUILTIN_FIND_HEADERS.H_MIT_KRB5=	kerberosv5/krb5.h
.else
BUILTIN_FIND_HEADERS.H_MIT_KRB5=	krb5.h
.endif
BUILTIN_FIND_GREP.H_MIT_KRB5=		Massachusetts Institute of Technology
BUILTIN_FIND_FILES_VAR:=		SH_KRB5_CONFIG
BUILTIN_FIND_FILES.SH_KRB5_CONFIG=	/usr/bin/krb5-config
BUILTIN_FIND_FILES.SH_KRB5_CONFIG+=	/usr/lib/mit/bin/krb5-config
BUILTIN_FIND_GREP.SH_KRB5_CONFIG=	^[ 	]*--version)

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.mit-krb5)
IS_BUILTIN.mit-krb5=	no
.  if empty(H_MIT_KRB5:M__nonexistent__) && empty(H_MIT_KRB5:M${LOCALBASE}/*)
IS_BUILTIN.mit-krb5=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.mit-krb5

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.mit-krb5) && \
    !empty(IS_BUILTIN.mit-krb5:M[yY][eE][sS])
.  if empty(SH_KRB5_CONFIG:M__nonexistent__)
BUILTIN_VERSION.mit-krb5!=	${SH_KRB5_CONFIG} --version | \
				${SED} -e 's/.*release //' -e 's/-.*//' -e 's/).*//'
.  endif
BUILTIN_VERSION.mit-krb5?=	1.4.0
BUILTIN_PKG.mit-krb5=		mit-krb5-${BUILTIN_VERSION.mit-krb5}
.endif
MAKEVARS+=			BUILTIN_PKG.mit-krb5

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.mit-krb5)
.  if ${PREFER.mit-krb5} == "pkgsrc"
USE_BUILTIN.mit-krb5=	no
.  else
USE_BUILTIN.mit-krb5=	${IS_BUILTIN.mit-krb5}
.    if defined(BUILTIN_PKG.mit-krb5) && \
        !empty(IS_BUILTIN.mit-krb5:M[yY][eE][sS])
USE_BUILTIN.mit-krb5=	yes
.      for dep__ in ${BUILDLINK_API_DEPENDS.mit-krb5}
.        if !empty(USE_BUILTIN.mit-krb5:M[yY][eE][sS])
USE_BUILTIN.mit-krb5!=							\
	if ${PKG_ADMIN} pmatch ${dep__:Q} ${BUILTIN_PKG.mit-krb5:Q}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=		USE_BUILTIN.mit-krb5

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.mit-krb5?=	no
.if !empty(CHECK_BUILTIN.mit-krb5:M[nN][oO])
.  if !empty(USE_BUILTIN.mit-krb5:M[yY][eE][sS])
KRB5_CONFIG?=	${SH_KRB5_CONFIG}
ALL_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}

BUILDLINK_CPPFLAGS.mit-krb5!=	${SH_KRB5_CONFIG} --cflags
BUILDLINK_LDFLAGS.mit-krb5!=	${SH_KRB5_CONFIG} --libs

#
# The SunOS builtin krb5-config does not support all of the arguments that the
# MIT version does so we install a fake script which strips them out.
#
.    if ${OPSYS} == "SunOS"
KRB5_CONFIG=			${BUILDLINK_DIR}/bin/krb5-config
BUILDLINK_CPPFLAGS.mit-krb5+=	-I/usr/include/gssapi
BUILDLINK_LDFLAGS.mit-krb5+=	-lgss
BUILDLINK_TARGETS+=		fake-krb5-config

.PHONY: fake-krb5-config
fake-krb5-config:
	${RUN}								\
	src=../../security/mit-krb5/files/krb5-config-wrapper.sh;	\
	dst=${BUILDLINK_DIR}/bin/krb5-config;				\
	if [ ! -f $${dst} ]; then					\
		${ECHO_BUILDLINK_MSG} "Creating $${dst}";		\
		${ECHO} "#!${SH}" > $${dst};				\
		${SED} -e "s,@KRB5_CONFIG@,${SH_KRB5_CONFIG:Q},g"	\
		    $${src} >> $${dst};					\
		${CHMOD} +x $${dst};					\
	fi

.    endif
.  else
KRB5_CONFIG?=	${BUILDLINK_PREFIX.mit-krb5}/bin/krb5-config
CONFIGURE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
MAKE_ENV+=	KRB5_CONFIG=${KRB5_CONFIG:Q}
.  endif

.endif	# CHECK_BUILTIN.mit-krb5
