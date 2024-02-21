# $NetBSD: builtin.mk,v 1.5 2024/02/21 10:21:00 wiz Exp $

BUILTIN_PKG:=	net-snmp

BUILTIN_FIND_FILES_VAR:=	H_NETSNMP
BUILTIN_FIND_FILES.H_NETSNMP=	/usr/include/net-snmp/net-snmp-config.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.net-snmp)
IS_BUILTIN.net-snmp=	no
.  if empty(H_NETSNMP:M__nonexistent__) && empty(H_NETSNMP:M${LOCALBASE}/*)
IS_BUILTIN.net-snmp=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.net-snmp

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.net-snmp) && \
    ${IS_BUILTIN.net-snmp:tl} == yes && \
    empty(H_NETSNMP:M__nonexistent__)
BUILTIN_VERSION.net-snmp!=				\
	${AWK} '/\#define[	 ]*PACKAGE_VERSION/ {	\
			vers = $$3;			\
			gsub("\"", "", vers);		\
			print vers;			\
		}					\
	' ${_CROSS_DESTDIR:U:Q}${H_NETSNMP:Q}
BUILTIN_PKG.net-snmp=	net-snmp-${BUILTIN_VERSION.net-snmp}
.endif
MAKEVARS+=		BUILTIN_PKG.net-snmp

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.net-snmp)
.  if ${PREFER.net-snmp} == "pkgsrc"
USE_BUILTIN.net-snmp=	no
.  else
USE_BUILTIN.net-snmp=	${IS_BUILTIN.net-snmp}
.    if defined(BUILTIN_PKG.net-snmp) && \
        ${IS_BUILTIN.net-snmp:tl} == yes
USE_BUILTIN.net-snmp=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.net-snmp}
.        if ${USE_BUILTIN.net-snmp:tl} == yes
USE_BUILTIN.net-snmp!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.net-snmp}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=		USE_BUILTIN.net-snmp
