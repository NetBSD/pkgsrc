# $NetBSD: builtin.mk,v 1.1 2004/04/26 05:09:29 jlam Exp $

_CDK_CDK_H=	/usr/include/cdk/cdk.h

.if !defined(IS_BUILTIN.cdk)
IS_BUILTIN.cdk=	no
.  if exists(${_CDK_CDK_H})
IS_BUILTIN.cdk=	yes
# XXX
# XXX Consider the native CDK to be cdk-4.9.9nb1.
# XXX
BUILTIN_PKG.cdk=	cdk-4.9.9nb1
BUILDLINK_VARS+=	BUILTIN_PKG.cdk
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.cdk
.endif	# IS_BUILTIN.cdk

.if !defined(USE_BUILTIN.cdk)
USE_BUILTIN.cdk?=	${IS_BUILTIN.cdk}
PREFER.cdk?=		pkgsrc

.  if defined(BUILTIN_PKG.cdk)
USE_BUILTIN.cdk=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.cdk}
.      if !empty(USE_BUILTIN.cdk:M[yY][eE][sS])
USE_BUILTIN.cdk!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.cdk}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif

.  if defined(USE_CDK)
.    if !empty(IS_BUILTIN.cdk:M[nN][oO]) && \
        (${PREFER.cdk} == "pkgsrc")
USE_BUILTIN.cdk=	no
.    endif
.  endif
.endif	# USE_BUILTIN.cdk
