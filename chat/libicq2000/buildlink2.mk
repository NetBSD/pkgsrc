.if !defined(LIBICQ2000_BUILDLINK2_MK)
LIBICQ2000_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libicq2000
BUILDLINK_DEPENDS.libicq2000=		libicq2000>=0.3.2
BUILDLINK_PKGSRCDIR.libicq2000?=	../../chat/libicq2000

EVAL_PREFIX+=				BUILDLINK_PREFIX.libicq2000=libicq2000
BUILDINK_PREFIX.libicq2000_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libicq2000=		include/libicq2000/libicq2000/*.h
BUILDLINK_FILES.libicq2000+=		lib/libicq2000.*

BUILDLINK_TARGETS+=	libicq2000-buildlink

libicq2000-buildlink: _BUILDLINK_USE

.include "../../devel/libsigc++10/buildlink2.mk"

.endif # LIBICQ2000_BUILDLINK2_MK
