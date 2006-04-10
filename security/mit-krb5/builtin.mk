# $NetBSD: builtin.mk,v 1.1 2006/04/10 15:04:44 tron Exp $

BUILTIN_PKG:=	mit-krb5

BUILTIN_FIND_FILES_VAR:=	KRB5_CONFIG
BUILTIN_FIND_FILES.KRB5_CONFIG=	/usr/bin/krb5-config

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Figure out the version of MIT Kerberos V installed on the system.
###

.if !defined(BUILTIN_VERSION.mit-krb5) && \
    empty(KRB5_CONFIG:M__nonexistent__) && \
    empty(KRB5_CONFIG:M${LOCALBASE}/*)
BUILTIN_VERSION.mit-krb5!=	${KRB5_CONFIG} --version | \
				${SED} -e 's/.*release //' -e 's/-.*//'
.endif
MAKEVARS+=	BUILTIN_VERSION.mit-krb5

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.mit-krb5)
IS_BUILTIN.mit-krb5=        no
.  if defined(BUILTIN_VERSION.mit-krb5)
IS_BUILTIN.mit-krb5=        yes
.  endif
.endif
MAKEVARS+=      IS_BUILTIN.mit-krb5

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.mit-krb5) && \
    !empty(IS_BUILTIN.mit-krb5:M[yY][eE][sS]) && \
    defined(BUILTIN_VERSION.mit-krb5)
BUILTIN_PKG.mit-krb5=       mit-krb5-${BUILTIN_VERSION.mit-krb5}
.endif
MAKEVARS+=      BUILTIN_PKG.mit-krb5

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
.      for _dep_ in ${BUILDLINK_API_DEPENDS.mit-krb5}
.        if !empty(USE_BUILTIN.mit-krb5:M[yY][eE][sS])
USE_BUILTIN.mit-krb5!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.mit-krb5:Q}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.mit-krb5
