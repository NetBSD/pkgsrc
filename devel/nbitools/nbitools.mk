# $NetBSD: nbitools.mk,v 1.2 2004/02/24 22:10:39 minskim Exp $
.if !defined(NBITOOLS_MK)
NBITOOLS_MK=	# defined

XMKMF_CMD=	${NBITOOLSDIR}/libexec/itools/xmkmf

.include "../../devel/nbitools/buildlink2.mk"

.endif	# NBITOOLS_MK
