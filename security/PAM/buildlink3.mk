# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PAM_BUILDLINK3_MK:=	${PAM_BUILDLINK3_MK}+

.if !empty(PAM_BUILDLINK3_MK:M\+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.pam?=		PAM>=0.75
BUILDLINK_PKGSRCDIR.pam?=	../../security/PAM
.endif	# PAM_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.pam?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.pam)
BUILDLINK_IS_BUILTIN.pam=	NO
.  if exists(/usr/include/security/pam_appl.h)
BUILDLINK_IS_BUILTIN.pam=	YES
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.pam:M[yY][eE][sS])
_NEED_PAM=	NO
.endif

.if !defined(_NEED_PAM)
.  if !empty(BUILDLINK_IS_BUILTIN.pam:M[nN][oO])
_NEED_PAM=	YES
.  else
_NEED_PAM=	NO
.  endif
MAKEFLAGS+=	_NEED_PAM="${_NEED_PAM}"
.endif

.if ${_NEED_PAM} == "YES"
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	pam
.  endif
.endif

.if !empty(PAM_BUILDLINK3_MK:M\+)
.  if ${_NEED_PAM} == "YES"
BUILDLINK_PACKAGES+=	pam
.  else
BUILDLINK_PREFIX.pam=	/usr
.  endif
.endif	# PAM_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
