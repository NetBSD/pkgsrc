# $NetBSD: hacks.mk,v 1.1 2005/07/18 07:25:33 grant Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=   rm:-O3
.endif    
