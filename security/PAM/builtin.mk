# $NetBSD: builtin.mk,v 1.3 2004/08/06 03:14:22 reed Exp $

.if !defined(IS_BUILTIN.pam)
IS_BUILTIN.pam=	no
.  if exists(/usr/include/security/pam_appl.h) && (${LOCALBASE} != "/usr")
IS_BUILTIN.pam=	yes
.  endif
.endif	# IS_BUILTIN.pam

USE_BUILTIN.pam?=	${IS_BUILTIN.pam}
