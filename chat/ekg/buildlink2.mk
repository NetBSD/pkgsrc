# $NetBSD: buildlink2.mk,v 1.2 2003/09/27 17:07:35 grant Exp $

.if !defined(EKG_BUILDLINK2_MK)
EKG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ekg
BUILDLINK_DEPENDS.ekg?=		ekg>=1.1
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg

EVAL_PREFIX+=		BUILDLINK_PREFIX.ekg=ekg
BUILDLINK_PREFIX.ekg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ekg=	include/libgadu*.h
BUILDLINK_FILES.ekg+=	lib/libgadu.*

.include "../../mk/curses.buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	ekg-buildlink

ekg-buildlink: _BUILDLINK_USE

.endif	# EKG_BUILDLINK2_MK
