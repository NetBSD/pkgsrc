# $NetBSD: Makefile,v 1.10 2003/07/21 16:30:38 martti Exp $
#

DISTNAME=		flac-1.1.0
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		Free lossless audio codec

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_XMMS_CONFIG="no"

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
