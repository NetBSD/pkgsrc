BUILDLINK_PACKAGES+=		libspf_alt
BUILDLINK_PKGBASE.libspf_alt=	libspf_alt
BUILDLINK_DEPENDS.libspf_alt?=	libspf_alt>=0.4.0
BUILDLINK_PKGSRCDIR.libspf_alt?=../../mail/libspf_alt

EVAL_PREFIX+=			BUILDLINK_PREFIX.libspf_alt=libspf_alt
BUILDLINK_PREFIX.libspf_alt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libspf_alt=	include/spf_alt/*
BUILDLINK_FILES.libspf_alt+=	lib/libspf_alt.*

BUILDLINK_TARGETS+=		libspf_alt-buildlink
libspf_alt-buildlink:		_BUILDLINK_USE
