# $NetBSD: Makefile,v 1.1.1.1 2001/07/23 18:16:10 wiz Exp $
#

DISTNAME=		flac-1.0-src
PKGNAME=		flac-xmms-1.0
WRKSRC=			${WRKDIR}/flac-1.0
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		FLAC xmms plugin

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
DEPENDS+=		xmms>=1.2.4:../../audio/xmms

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-*-i386} != ""
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-configure:
	(cd ${WRKSRC}/src/libFLAC/ia32 && \
		${MV} Makefile.am Makefile.am.orig && \
		${CP} Makefile.am.libtool-1.4b Makefile.am)
	(cd ${WRKSRC} && ${LOCALBASE}/bin/automake)

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/src/plugin_xmms/libxmms-flac.la \
		${PREFIX}/lib/xmms/Input

.include "../../mk/bsd.pkg.mk"
