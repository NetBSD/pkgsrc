# $NetBSD: Makefile,v 1.3 2001/08/13 20:07:17 nra Exp $
#

DISTNAME=		flac-1.0-src
PKGNAME=		flac-xmms-1.0
WRKSRC=			${WRKDIR}/flac-1.0/src/plugin_xmms/
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		FLAC xmms plugin

DEPENDS+=		xmms>=1.2.4:../../audio/xmms

MAKEFILE=		Makefile.lite
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../../obj/lib/libxmms-flac.so \
		${PREFIX}/lib/xmms/Input

.include "../../audio/flac/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
