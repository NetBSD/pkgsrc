# $NetBSD: hacks.mk,v 1.2 2006/05/14 21:10:01 schwarz Exp $

.if !defined(ORBIT_HACKS_MK)
ORBIT_HACKS_MK=	# defined

### [Sun Apr 30 22:45:25 CDT 2006 : schwarz]
### Make sure ORBit does not define socklen_t if it has already been
### typedef'd in devel/pth's pthread.h.
### This works around the problem reported in pkg/27009.
###
.if exists(${LOCALBASE}/include/pthread.h)
_SOCKLEN_T_TYPEDEFD!=	${GREP} -c '^typedef\ .*\ socklen_t;$$' ${LOCALBASE}/include/pthread.h || ${TRUE}
.  if ${_SOCKLEN_T_TYPEDEFD} == "1"
PKG_HACKS+=		socklen_t-already-typedefd-in-pthread.h
SUBST_CLASSES+=		socklen_t
SUBST_FILES.socklen_t=	configure
SUBST_STAGE.socklen_t=	post-patch
SUBST_SED.socklen_t=	-e 's/^\#define\ socklen_t\ size_t$$//'
# remark: \ before # needed to prevent make from interpreting
#         remainder of line as a comment
.  endif
.endif

.endif
