# $NetBSD: buildlink2.mk,v 1.7 2004/03/26 02:27:39 wiz Exp $

.if !defined(SUBVERSION_BUILDLINK2_MK)
SUBVERSION_BUILDLINK2_MK=		#defined

BUILDLINK_PACKAGES+=			subversion-base
BUILDLINK_DEPENDS.subversion-base?=	subversion-base>=${SVNVER}
BUILDLINK_RECOMMENDED.subversion-base?=	subversion>=1.0.0nb1
BUILDLINK_PKGSRCDIR.subversion-base?=	../../devel/subversion-base

EVAL_PREFIX+=			BUILDLINK_PREFIX.subversion-base=subversion-base
BUILDLINK_PREFIX.subversion-base_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.subversion-base+=	bin/svn-config
BUILDLINK_FILES.subversion-base+=	include/subversion-1/*
BUILDLINK_FILES.subversion-base+=	lib/libsvn*

.include "../../databases/db4/buildlink2.mk"
.include "../../devel/apr/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"

.include "../../devel/subversion/Makefile.version"

BUILDLINK_TARGETS+=		subversion-base-buildlink

subversion-base-buildlink: _BUILDLINK_USE

.endif	# SUBVERSION_BUILDLINK2_MK
