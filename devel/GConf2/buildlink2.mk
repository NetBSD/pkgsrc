# $NetBSD: buildlink2.mk,v 1.5 2002/09/11 09:13:08 wiz Exp $

.if !defined(GCONF2_BUILDLINK2_MK)
GCONF2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gconf2
BUILDLINK_DEPENDS.gconf2?=	GConf2>=1.2.1nb1
BUILDLINK_PKGSRCDIR.gconf2?=	../../devel/GConf2

EVAL_PREFIX+=				BUILDLINK_PREFIX.gconf2=GConf2
BUILDLINK_PREFIX.gconf2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gconf2=			include/gconf/2/gconf/*
BUILDLINK_FILES.gconf2+=		lib/libgconf-2*

.include "../../databases/db3/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	gconf2-buildlink

gconf2-buildlink: _BUILDLINK_USE

.endif	# GCONF2_BUILDLINK2_MK
