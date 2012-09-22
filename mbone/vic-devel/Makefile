# $NetBSD: Makefile,v 1.7 2012/09/22 13:48:17 ryoon Exp $

DISTNAME=	vic-2.8ucl1.4.0beta-4337
PKGNAME=	vic-devel-2.8.1.4.0beta.4337
PKGREVISION=	5
CATEGORIES=	mbone tk
MASTER_SITES=	http://www.NetBSD.org/~sborrill/snapshots/

MAKE_JOBS_SAFE=	no

PKG_DESTDIR_SUPPORT=	user-destdir

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
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

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
