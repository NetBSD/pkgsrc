# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/25 08:55:19 epg Exp $
#

.if !defined(APR_BUILDLINK2_MK)
APR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		apr
BUILDLINK_DEPENDS.apr?=		apr>=0.9.1.2.0.45
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr

EVAL_PREFIX+=			BUILDLINK_PREFIX.apr=apr
BUILDLINK_PREFIX.apr_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.apr+=	bin/apr-config
BUILDLINK_FILES.apr+=	bin/apu-config
BUILDLINK_FILES.apr+=	include/apr-0/*
BUILDLINK_FILES.apr+=	lib/apr.exp
BUILDLINK_FILES.apr+=	lib/aprutil.exp
BUILDLINK_FILES.apr+=	lib/libapr-0.*
BUILDLINK_FILES.apr+=	lib/libaprutil-0.*

.include "../../textproc/expat/buildlink2.mk"

BUILDLINK_TARGETS+=	apr-buildlink

apr-buildlink: _BUILDLINK_USE

.endif	# APR_BUILDLINK2_MK
