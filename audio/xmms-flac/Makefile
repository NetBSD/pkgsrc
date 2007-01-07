# $NetBSD: Makefile,v 1.23 2007/01/07 12:54:22 wiz Exp $
#

DISTNAME=	flac-1.1.3
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flac.sourceforge.net/
COMMENT=	FLAC XMMS plugin

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool-disable-static

XMMS_WRKSRC=	${WRKSRC}/src/plugin_xmms

# previous name of the package
CONFLICTS=	flac-xmms-[0-9]*

BUILD_DIRS=	src/libFLAC
BUILD_DIRS+=	src/plugin_common
BUILD_DIRS+=	src/share
BUILD_DIRS+=	src/plugin_xmms
INSTALL_DIRS=	src/plugin_xmms

.include "../../mk/compiler.mk"

# SunPro does not support __inline
.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-D__inline=inline
.endif

do-install:
	cd ${XMMS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} ${INSTALL_TARGET}

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
