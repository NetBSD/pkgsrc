# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:53:31 wiz Exp $

.if !defined(EB_BUILDLINK2_MK)
EB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		eb

# eb<=3.2.1 packages didn't fix eb.conf.
BUILDLINK_DEPENDS.eb?=		eb>=3.3.2nb1
BUILDLINK_PKGSRCDIR.eb?=	../../textproc/eb

EVAL_PREFIX+=			BUILDLINK_PREFIX.eb=eb
BUILDLINK_PREFIX.eb_DEFAULT?=	${LOCALBASE}

BUILDLINK_FILES.eb=	include/eb/*.h
BUILDLINK_FILES.eb+=	lib/libeb.*

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-eb-conf=${PKG_SYSCONFDIR}/eb.conf
.endif

BUILDLINK_TARGETS+=	eb-buildlink

eb-buildlink: _BUILDLINK_USE

.endif	# EB_BUILDLINK2_MK
