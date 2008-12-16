# $NetBSD: Makefile,v 1.1.1.1 2008/12/16 19:35:45 sborrill Exp $

DISTNAME=	vic-2.8ucl1.4.0beta-4337
PKGNAME=	vic-devel-2.8.1.4.0beta.4337
CATEGORIES=	mbone tk
MASTER_SITES=	http://www.NetBSD.org/~sborrill/snapshots/

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-1.6*) || !empty(MACHINE_PLATFORM:MNetBSD-[2-9]*)
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	vic-2.8ucl1.4.0_ov511.diff.gz
.endif

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://mediatools.cs.ucl.ac.uk/nets/mmedia/
COMMENT=	MBONE video conferencing tool
EXTRACT_SUFX=	.tgz

WRKSRC=		${WRKDIR}/vic-mpeg4
GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/videoio.h)
.include "../../graphics/libv4l/buildlink3.mk"
.endif

CONFLICTS+=	vic-[0-9]*

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mbone/common-mml/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
