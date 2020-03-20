# $NetBSD: Makefile,v 1.33 2020/03/20 11:57:23 nia Exp $
#

DISTNAME=	flac-1.1.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flac.sourceforge.net/
COMMENT=	FLAC XMMS plugin
LICENSE=	gnu-gpl-v2

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

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
