# $NetBSD: buildlink3.mk,v 1.4 2004/01/05 11:05:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GETOPT_BUILDLINK3_MK:=	${GETOPT_BUILDLINK3_MK}+

.if !empty(GETOPT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		getopt
BUILDLINK_DEPENDS.getopt?=	libgetopt>=1.3
BUILDLINK_PKGSRCDIR.getopt?=	../../devel/libgetopt
.endif	# GETOPT_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.getopt?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.getopt)
BUILDLINK_IS_BUILTIN.getopt=	NO
.  if exists(/usr/include/getopt.h)
BUILDLINK_IS_BUILTIN.getopt=	YES
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.getopt:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.getopt=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.getopt)
.  if !empty(BUILDLINK_IS_BUILTIN.getopt:M[nN][oO])
BUILDLINK_USE_BUILTIN.getopt=	NO
.  else
BUILDLINK_USE_BUILTIN.getopt=	YES
.  endif
.endif

.if !empty(BUILDLINK_USE_BUILTIN.getopt:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	getopt
.  endif
.endif

.if !empty(GETOPT_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.getopt:M[nN][oO])
LIBGETOPT=	-lgetopt
.  else
LIBGETOPT=	# empty
.  endif

BUILDLINK_LDADD.getopt?=	${LIBGETOPT}

CONFIGURE_ENV+=		LIBGETOPT="${LIBGETOPT}"
MAKE_ENV+=		LIBGETOPT="${LIBGETOPT}"
.endif	# GETOPT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
