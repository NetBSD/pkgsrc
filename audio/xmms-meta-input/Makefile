# $NetBSD: Makefile,v 1.1.1.1 2003/12/24 00:09:55 ben Exp $
#

DISTNAME=		xmms-meta-input-0.4
CATEGORIES=		audio
MASTER_SITES=		http://www.corbac.com/Data/Sources/

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.corbac.com/page3.html
COMMENT=		XMMS plugin wrapper for shell scripts

USE_BUILDLINK2=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmetainput.so ${PREFIX}/lib/xmms/Input
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xmms/Input/Meta
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmms-input
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmms-input
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xmms-meta-input
	cd ${WRKSRC}/Examples && ${INSTALL_SCRIPT} dsp_input esound_link midi \
		modules mp3 spc vorbis ${PREFIX}/share/examples/xmms-meta-input

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
