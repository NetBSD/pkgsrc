# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:34 jlam Exp $

DISTNAME=	mencvcd
PKGNAME=	${DISTNAME}-0.3
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://hammelmann.gmxhome.de/
EXTRACT_SUFX=

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://hammelmann.gmxhome.de/projects_en.html
COMMENT=	Script for converting movie files into (S)VCD format

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	cdrdao>=1.1.9:../../sysutils/cdrdao
DEPENDS+=	lame>=3.96.1:../../audio/lame
DEPENDS+=	mjpegtools>=1.6.2:../../multimedia/mjpegtools
DEPENDS+=	mplayer>=1.0rc1:../../multimedia/mplayer
DEPENDS+=	normalize>=0.7.6:../../audio/normalize
DEPENDS+=	sox>=12.16:../../audio/sox
DEPENDS+=	vcdimager>=0.6.2:../../sysutils/vcdimager

NO_CONFIGURE=	YES
DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -p ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

do-build:
	${ECHO} "#!${LOCALBASE}/bin/bash" >${WRKSRC}/mencvcd.bash
	${TAIL} +2 ${WRKSRC}/mencvcd >>${WRKSRC}/mencvcd.bash

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mencvcd.bash ${PREFIX}/bin/mencvcd

.include "../../mk/bsd.pkg.mk"
