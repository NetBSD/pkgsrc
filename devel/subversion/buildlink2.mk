# $NetBSD: buildlink2.mk,v 1.3 2003/05/02 11:54:42 wiz Exp $
#

.if !defined(SUBVERSION_BUILDLINK2_MK)
SUBVERSION_BUILDLINK2_MK=          #defined

BUILDLINK_PACKAGES+=			subversion-base
BUILDLINK_DEPENDS.subversion-base?=	subversion>=0.20.1nb1
BUILDLINK_PKGSRCDIR.subversion-base?=	../../devel/subversion

EVAL_PREFIX+=	BUILDLINK_PREFIX.subversion-base=subversion
BUILDLINK_PREFIX.subversion-base_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.subversion-base+=	bin/svn-config
BUILDLINK_FILES.subversion-base+=	include/subversion-1/*
BUILDLINK_FILES.subversion-base+=	lib/libsvn*

.include "../../databases/db4/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"

BUILDLINK_TARGETS+=             subversion-base-buildlink

subversion-base-buildlink:	_BUILDLINK_USE

.endif  # SUBVERSION_BUILDLINK2_MK
