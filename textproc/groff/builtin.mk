# $NetBSD: builtin.mk,v 1.2 2004/07/09 12:30:17 drochner Exp $

.if !defined(IS_BUILTIN.groff)
.  if exists(/usr/bin/groff)
IS_BUILTIN.groff=	yes
_GROFFPATH=		/usr/bin
.  else
IS_BUILTIN.groff=	no
_GROFFPATH=		${LOCALBASE}/bin
.  endif
.endif  # IS_BUILTIN.groff

USE_BUILTIN.groff?=	${IS_BUILTIN.groff}
GROFF?=			${_GROFFPATH}/groff
TBL?=			${_GROFFPATH}/tbl
