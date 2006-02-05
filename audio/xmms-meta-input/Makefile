# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:18 joerg Exp $
#

DISTNAME=		xmms-meta-input-0.4
PKGREVISION=	2
CATEGORIES=		audio
MASTER_SITES=		http://www.corbac.com/Data/Sources/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.corbac.com/page3.html
COMMENT=		XMMS plugin wrapper for shell scripts

INSTALLATION_DIRS=	lib/xmms/Input

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmetainput.so ${PREFIX}/lib/xmms/Input
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xmms/Input/Meta
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmms-input
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmms-input
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xmms-meta-input
	cd ${WRKSRC}/Examples && ${INSTALL_SCRIPT} dsp_input esound_link midi \
		modules mp3 spc vorbis ${PREFIX}/share/examples/xmms-meta-input

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
