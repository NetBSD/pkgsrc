# $NetBSD: Makefile,v 1.5 2002/11/10 23:55:13 lukem Exp $
#

DISTNAME=		flac-1.0.4
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		free lossless audio codec

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
