# $NetBSD: nbitools.mk,v 1.1.1.1.4.2 2002/06/23 18:44:37 jlam Exp $
.if !defined(NBITOOLS_MK)
NBITOOLS_MK=	# defined

BUILD_DEPENDS+=	nbitools>=6.3:../../devel/nbitools
EVAL_PREFIX+=	NBITOOLSDIR=nbitools
XMKMF_CMD=	${NBITOOLSDIR}/libexec/itools/xmkmf

.endif	# NBITOOLS_MK
