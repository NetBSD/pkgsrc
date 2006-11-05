# $NetBSD: bsd.fast.prefs.mk,v 1.1 2006/11/05 14:28:38 joerg Exp $
#
# Conditionally include mk/bsd.prefs.mk, if it wasn't processed already.
#

.if !defined(BSD_PKG_MK)
.include "../../mk/bsd.prefs.mk"
.endif
