BUILDLINK_PACKAGES+=		libsnert
BUILDLINK_PKGBASE.libsnert=	libsnert
BUILDLINK_DEPENDS.libsnert?=	libsnert>=1.23
BUILDLINK_PKGSRCDIR.libsnert?=	../../mail/libsnert
	
EVAL_PREFIX+=			BUILDLINK_PREFIX.libsnert=libsnert
BUILDLINK_PREFIX.libsnert_DEFAULT= ${LOCALBASE}
BUILDLINK_FILES.libsnert=	include/com/snert/lib/*.h
BUILDLINK_FILES.libsnert+=	include/com/snert/lib/crc/*.h
BUILDLINK_FILES.libsnert+=	include/com/snert/lib/io/*.h
BUILDLINK_FILES.libsnert+=	include/com/snert/lib/sys/*.h
BUILDLINK_FILES.libsnert+=	include/com/snert/lib/util/*.h
BUILDLINK_FILES.libsnert+=	lib/libsnert.a
	
BUILDLINK_TARGETS+=		libsnert-buildlink
	
libsnert-buildlink: 		_BUILDLINK_USE
