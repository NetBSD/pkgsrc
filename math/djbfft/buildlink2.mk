BUILDLINK_PACKAGES+=			djbfft
BUILDLINK_PKGBASE.djbfft=		djbfft
BUILDLINK_DEPENDS.djbfft?=		djbfft>=0.76
BUILDLINK_PKGSRCDIR.djbfft?=		../../math/djbfft

EVAL_PREFIX+=				BUILDLINK_PREFIX.djbfft=djbfft
BUILDLINK_PREFIX.djbfft_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.djbfft=			include/djbfft/complex4.h
BUILDLINK_FILES.djbfft+=		include/djbfft/complex8.h
BUILDLINK_FILES.djbfft+=                include/djbfft/fftc4.h
BUILDLINK_FILES.djbfft+=                include/djbfft/fftc8.h
BUILDLINK_FILES.djbfft+=                include/djbfft/fftfreq.h
BUILDLINK_FILES.djbfft+=                include/djbfft/fftr4.h
BUILDLINK_FILES.djbfft+=                include/djbfft/fftr8.h
BUILDLINK_FILES.djbfft+=                include/djbfft/real4.h
BUILDLINK_FILES.djbfft+=                include/djbfft/real8.h
BUILDLINK_FILES.djbfft+=                lib/libdjbfft.a

BUILDLINK_TARGETS+=			djbfft-buildlink

djbfft-buildlink: _BUILDLINK_USE
