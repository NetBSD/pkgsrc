# $NetBSD: Makefile,v 1.12 2003/12/08 14:42:44 wiz Exp $
#

DISTNAME=		flac-1.1.0
PKGREVISION=				1
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://flac.sourceforge.net/
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
