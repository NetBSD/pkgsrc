# $NetBSD: Makefile,v 1.18 2022/04/24 15:00:42 nia Exp $

DISTNAME=	MPlayer-1.5
PKGNAME=	${DISTNAME:S/MPlayer/mencvcd/}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/releases/
DIST_SUBDIR=	mplayer
EXTRACT_SUFX=	.tar.xz

MAINTAINER?=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://hammelmann.gmxhome.de/projects_en.html
HOMEPAGE=	http://www.mplayerhq.hu/
COMMENT=	Script for converting movie files into (S)VCD format
LICENSE=	gnu-gpl-v2 # just says "GPL"

DEPENDS+=	cdrdao>=1.1.9:../../sysutils/cdrdao
DEPENDS+=	lame>=3.96.1:../../audio/lame
DEPENDS+=	mjpegtools>=1.6.2:../../multimedia/mjpegtools
DEPENDS+=	mplayer>=1.0rc1:../../multimedia/mplayer
DEPENDS+=	normalize>=0.7.6:../../audio/normalize
DEPENDS+=	sox>=12.16:../../audio/sox
DEPENDS+=	vcdimager>=0.6.2:../../sysutils/vcdimager

CHECK_PORTABILITY_SKIP=	ffmpeg/configure # not used by package

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

REPLACE_BASH=	TOOLS/mencvcd.sh
USE_TOOLS+=	bash:run

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/TOOLS/mencvcd.sh ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
