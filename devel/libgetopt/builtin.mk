# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:30 jlam Exp $

.if !defined(IS_BUILTIN.getopt)
IS_BUILTIN.getopt=	no
.  if exists(/usr/include/getopt.h)
IS_BUILTIN.getopt=	yes
.  endif
.endif	# IS_BUILTIN.getopt

USE_BUILTIN.getopt?=	${IS_BUILTIN.getopt}

CHECK_BUILTIN.getopt?=	no
.if !empty(CHECK_BUILTIN.getopt:M[nN][oO])

.if !empty(USE_BUILTIN.getopt:M[nN][oO])
LIBGETOPT=	-lgetopt
.else
LIBGETOPT=	# empty
.endif

BUILDLINK_LDADD.getopt?=	${LIBGETOPT}

CONFIGURE_ENV+=		LIBGETOPT="${LIBGETOPT}"
MAKE_ENV+=		LIBGETOPT="${LIBGETOPT}"

.endif	# CHECK_BUILTIN.getopt
