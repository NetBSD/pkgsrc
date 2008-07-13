# $NetBSD: hacks.mk,v 1.1 2008/07/13 14:25:04 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:MIRIX*)
CPPFLAGS+=	-Dvfork=fork
CONFIGURE_ENV+=	ac_cv_func_vfork=yes
.endif
