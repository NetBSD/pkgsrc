# $NetBSD: buildlink2.mk,v 1.4 2003/02/19 14:20:03 jmmv Exp $

.if !defined(INTLTOOL_BUILDLINK2_MK)
INTLTOOL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		intltool
BUILDLINK_DEPENDS.intltool?=	intltool>=0.25nb1
BUILDLINK_PKGSRCDIR.intltool?=	../../textproc/intltool
BUILDLINK_DEPMETHOD.intltool?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.intltool=intltool
BUILDLINK_PREFIX.intltool_DEFAULT=	${LOCALBASE}

USE_PERL5?=	build
.include "../../lang/perl5/buildlink2.mk"

BUILDLINK_TARGETS+=	intltool-buildlink

intltool-buildlink: _BUILDLINK_USE

.endif	# INTLTOOL_BUILDLINK2_MK
