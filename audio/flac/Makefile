# $NetBSD: Makefile,v 1.16 2004/01/22 07:15:00 grant Exp $
#

DISTNAME=		flac-1.1.0
PKGREVISION=				1
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://flac.sourceforge.net/
COMMENT=		Free lossless audio codec

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_XMMS_CONFIG="no"

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
