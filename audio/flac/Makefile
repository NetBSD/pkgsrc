# $NetBSD: Makefile,v 1.18 2004/02/03 12:38:51 abs Exp $
#

DISTNAME=		flac-1.1.0
PKGREVISION=		1
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://flac.sourceforge.net/
COMMENT=		Free lossless audio codec

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_XMMS_CONFIG="no"

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

# This version of flac doesn't seem to build correctly with -O3 using
# the MIPSpro compiler.
#
.if defined(USE_MIPSPRO)
BUILDLINK_TRANSFORM+=	S:-O3:
.endif

.include "../../audio/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
