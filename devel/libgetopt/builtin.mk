# $NetBSD: builtin.mk,v 1.1 2004/03/10 17:57:14 jlam Exp $

.if !defined(IS_BUILTIN.getopt)
IS_BUILTIN.getopt=	no
.  if exists(/usr/include/getopt.h)
IS_BUILTIN.getopt=	yes
.  endif
.endif

CHECK_BUILTIN.getopt?=	no
.if !empty(CHECK_BUILTIN.getopt:M[yY][eE][sS])
USE_BUILTIN.getopt=	yes
.endif

USE_BUILTIN.getopt?=	${IS_BUILTIN.getopt}

.if !empty(USE_BUILTIN.getopt:M[nN][oO])
LIBGETOPT=	-lgetopt
.else
LIBGETOPT=	# empty
.endif

BUILDLINK_LDADD.getopt?=	${LIBGETOPT}

CONFIGURE_ENV+=		LIBGETOPT="${LIBGETOPT}"
MAKE_ENV+=		LIBGETOPT="${LIBGETOPT}"
