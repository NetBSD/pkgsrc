# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:10 jlam Exp $

.if !defined(BONOBO_CONF_BUILDLINK2_MK)
BONOBO_CONF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			bonobo-conf
BUILDLINK_DEPENDS.bonobo-conf?=		bonobo-conf>0.14nb1
BUILDLINK_PKGSRCDIR.bonobo-conf?=	../../devel/bonobo-conf

EVAL_PREFIX+=			BUILDLINK_PREFIX.bonobo-conf=bonobo-conf
BUILDLINK_PREFIX.bonobo-conf_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.bonobo-conf=		include/bonobo-conf/*
BUILDLINK_FILES.bonobo-conf+=		lib/bonobo/monikers/libmoniker_config*
BUILDLINK_FILES.bonobo-conf+=		lib/bonobo/monikers/libmoniker_gconf*
BUILDLINK_FILES.bonobo-conf+=		lib/bonobo_conf*
BUILDLINK_FILES.bonobo-conf+=		lib/libbonobo_conf*

.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"

BUILDLINK_TARGETS+=	bonobo-conf-buildlink

bonobo-conf-buildlink: _BUILDLINK_USE

.endif	# BONOBO_CONF_BUILDLINK2_MK
