# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/04/01 18:35:35 jschauma Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TEEM_BUILDLINK3_MK:=	${TEEM_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	teem
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nteem}
BUILDLINK_PACKAGES+=	teem

.if !empty(TEEM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.teem+=		teem>=1.8.0
BUILDLINK_PKGSRCDIR.teem?=		../../devel/teem

BUILDLINK_FILES.teem+=	include/teem/*
BUILDLINK_FILES.teem+=	include/teem32bit.h include/teemDio.h
BUILDLINK_FILES.teem+=	include/teemEndian.h include/teemPng.h
BUILDLINK_FILES.teem+=	include/teemQnanhibit.h

BUILDLINK_FILES.teem+=	lib/libair.*
BUILDLINK_FILES.teem+=  lib/libalan.*
BUILDLINK_FILES.teem+=  lib/libbane.*
BUILDLINK_FILES.teem+=  lib/libbiff.*
BUILDLINK_FILES.teem+=  lib/libcoil.*
BUILDLINK_FILES.teem+=  lib/libdye.*
BUILDLINK_FILES.teem+=  lib/libecho.*
BUILDLINK_FILES.teem+=  lib/libell.*
BUILDLINK_FILES.teem+=  lib/libgage.*
BUILDLINK_FILES.teem+=  lib/libhest.*
BUILDLINK_FILES.teem+=  lib/libhoover.*
BUILDLINK_FILES.teem+=  lib/liblimn.*
BUILDLINK_FILES.teem+=  lib/libmite.*
BUILDLINK_FILES.teem+=  lib/libmoss.*
BUILDLINK_FILES.teem+=  lib/libnrrd.*
BUILDLINK_FILES.teem+=  lib/libteem.*
BUILDLINK_FILES.teem+=  lib/libten.*
BUILDLINK_FILES.teem+=  lib/libunrrdu.*

.endif	# TEEM_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
