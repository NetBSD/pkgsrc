# $NetBSD: builtin.mk,v 1.3 2005/03/14 19:48:52 tv Exp $

.if !defined(IS_BUILTIN.groff)
.  if exists(/usr/bin/groff)
IS_BUILTIN.groff=	yes
.  else
IS_BUILTIN.groff=	no
.  endif
.endif  # IS_BUILTIN.groff

USE_BUILTIN.groff?=	${IS_BUILTIN.groff}
GROFF?=			${BUILDLINK_PREFIX.groff}/bin/groff
TBL?=			${BUILDLINK_PREFIX.groff}/bin/tbl
