# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/05 22:54:11 xtraeme Exp $

.if !defined(LIBSOUP_BUILDLINK2_MK)
LIBSOUP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libsoup
BUILDLINK_DEPENDS.libsoup?=		libsoup>=1.99.26
BUILDLINK_PKGSRCDIR.libsoup?=		../../net/libsoup

EVAL_PREFIX+=	BUILDLINK_PREFIX.libsoup=libsoup
BUILDLINK_PREFIX.libsoup_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-address.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-context.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-error.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-headers.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-message.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-method.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-misc.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-ntlm.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-server-auth.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-server.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-socket.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup-uri.h
BUILDLINK_FILES.libsoup+=	include/soup-2.0/libsoup/soup.h
BUILDLINK_FILES.libsoup+=	lib/libsoup-2.0.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	libsoup-buildlink

libsoup-buildlink: _BUILDLINK_USE

.endif	# LIBSOUP_BUILDLINK2_MK
