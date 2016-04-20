# $NetBSD: Makefile,v 1.22 2016/04/20 12:10:34 nros Exp $
#

DISTNAME=		xmms-meta-input-0.4
PKGREVISION=		8
CATEGORIES=		audio
MASTER_SITES=		http://www.corbac.com/Data/Sources/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.corbac.com/page3.html
COMMENT=		XMMS plugin wrapper for shell scripts
LICENSE=		gnu-gpl-v2

INSTALLATION_DIRS=	lib/xmms/Input
REQD_DIRS+=		lib/xmms/Input/Meta

USE_LIBTOOL=		yes

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/libmetainput.la ${DESTDIR}${PREFIX}/lib/xmms/Input
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/xmms/Input/Meta
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xmms-input
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xmms-input
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/xmms-meta-input
	cd ${WRKSRC}/Examples && ${INSTALL_SCRIPT} dsp_input esound_link midi \
		modules mp3 spc vorbis \
		${DESTDIR}${PREFIX}/share/examples/xmms-meta-input

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
