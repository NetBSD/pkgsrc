# $NetBSD: Makefile,v 1.3 2005/01/28 09:11:13 tron Exp $

DISTNAME=	mencvcd
PKGNAME=	${DISTNAME}-0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://hammelmann.gmxhome.de/
EXTRACT_SUFX=

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://hammelmann.gmxhome.de/projects_en.html
COMMENT=	Script for converting movie files into (S)VCD format

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	lame>=3.96.1:../../audio/lame
DEPENDS+=	mjpegtools>=1.6.2:../../multimedia/mjpegtools
DEPENDS+=	mplayer>=1.0rc1:../../multimedia/mplayer
DEPENDS+=	normalize>=0.7.6:../../audio/normalize
DEPENDS+=	sox>=12.16:../../audio/sox
DEPENDS+=	vcdimager>=0.6.2:../../sysutils/vcdimager

EXTRACT_ONLY=
NO_CONFIGURE=	YES
DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}

do-build:
	${ECHO} "#!${LOCALBASE}/bin/bash" >${WRKSRC}/mencvcd
	${TAIL} +2 ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} >>${WRKSRC}/mencvcd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mencvcd ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
