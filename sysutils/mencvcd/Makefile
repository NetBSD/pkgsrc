# $NetBSD: Makefile,v 1.2 2005/01/28 01:28:15 wiz Exp $

.include "../../multimedia/mplayer-share/Makefile.common"

PKGNAME=	mencvcd-0.2.2
CATEGORIES=	sysutils

MAINTAINER=	tron@NetBSD.org
COMMENT=	Script for converting movie files into (S)VCD format

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	mjpegtools>=1.6.2:../../multimedia/mjpegtools
DEPENDS+=	mplayer>=${MPLAYER_PKG_VERSION}:../../multimedia/mplayer
DEPENDS+=	sox>=12.16:../../audio/sox
DEPENDS+=	vcdimager>=0.6.2:../../sysutils/vcdimager

NO_CONFIGURE=	YES

MENCVCD=	${WRKSRC}/TOOLS/mencvcd

do-build:
	${MV} ${MENCVCD} ${MENCVCD}.old
	${ECHO} "#!${LOCALBASE}/bin/bash" >${MENCVCD}
	${TAIL} +2 ${MENCVCD}.old >>${MENCVCD}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/TOOLS/mencvcd ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
