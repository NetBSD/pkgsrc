# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:40:02 jlam Exp $

.if !defined(INTLTOOL_BUILDLINK2_MK)
INTLTOOL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		intltool
BUILDLINK_DEPENDS.intltool?=	intltool>=0.18
BUILDLINK_PKGSRCDIR.intltool?=	../../textproc/intltool

EVAL_PREFIX+=	BUILDLINK_PREFIX.intltool=intltool
BUILDLINK_PREFIX.intltool_DEFAULT=	${LOCALBASE}

.include "../../lang/perl5/buildlink2.mk"

BUILDLINK_TARGETS+=	intltool-buildlink

intltool-buildlink: _BUILDLINK_USE

.endif	# INTLTOOL_BUILDLINK2_MK
