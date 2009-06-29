# $NetBSD: Makefile,v 1.38 2009/06/29 15:53:35 joerg Exp $

DISTNAME=	vicsrc-2.8
PKGNAME=	${DISTNAME:S/src//}
PKGREVISION=	3
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-1.6*) || !empty(MACHINE_PLATFORM:MNetBSD-[2-9]*)
PATCH_SITES=	ftp://tink.ims.ac.jp/pub/NetBSD/vic/
PATCHFILES=	vic-2.8_ov511p0.diff.gz
.endif

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vic/
COMMENT=	MBONE video conferencing tool

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
