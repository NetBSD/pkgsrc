# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GETOPT_BUILDLINK3_MK:=	${GETOPT_BUILDLINK3_MK}+

.if !empty(GETOPT_BUILDLINK3_MK:M\+)
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
_NEED_GETOPT=	NO
.endif

.if !defined(_NEED_GETOPT)
.  if !empty(BUILDLINK_IS_BUILTIN.getopt:M[nN][oO])
_NEED_GETOPT=	YES
.  else
_NEED_GETOPT=	NO
.  endif
MAKEFLAGS+=	_NEED_GETOPT="${_NEED_GETOPT}"
.endif

.if ${_NEED_GETOPT} == "YES"
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	getopt
.  endif
.endif

.if !empty(GETOPT_BUILDLINK3_MK:M\+)
.  if ${_NEED_GETOPT} == "YES"
BUILDLINK_PACKAGES+=		getopt
LIBGETOPT=			-lgetopt
.  else
BUILDLINK_PREFIX.getopt=	/usr
LIBGETOPT=			# empty
.  endif

BUILDLINK_LDADD.getopt?=	${LIBGETOPT}

CONFIGURE_ENV+=			LIBGETOPT="${LIBGETOPT}"
MAKE_ENV+=			LIBGETOPT="${LIBGETOPT}"
.endif	# GETOPT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
