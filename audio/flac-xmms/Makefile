# $NetBSD: Makefile,v 1.4 2002/04/27 10:12:40 rh Exp $
#

DISTNAME=		flac-1.0.2-src
PKGNAME=		flac-xmms-1.0.2
WRKSRC=			${WRKDIR}/flac-1.0.2/src/plugin_xmms/
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		FLAC xmms plugin

MAKEFILE=		Makefile.lite
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../../obj/lib/libxmms-flac.so \
		${PREFIX}/lib/xmms/Input

.include "../../audio/flac/buildlink.mk"
.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
