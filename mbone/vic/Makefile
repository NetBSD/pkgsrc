# $NetBSD: Makefile,v 1.35 2006/05/13 13:18:20 joerg Exp $

DISTNAME=	vicsrc-2.8
PKGNAME=	${DISTNAME:S/src//}
PKGREVISION=	3
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-1.6*) || !empty(MACHINE_PLATFORM:MNetBSD-[2-9]*)
PATCH_SITES=    ftp://tink.ims.ac.jp/pub/NetBSD/vic/
PATCHFILES=     vic-2.8_ov511p0.diff.gz
.endif

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vic/
COMMENT=	MBONE video conferencing tool

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
