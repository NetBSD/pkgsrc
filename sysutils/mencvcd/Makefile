# $NetBSD: Makefile,v 1.16 2017/09/03 08:37:00 wiz Exp $

DISTNAME=	mencvcd
PKGNAME=	${DISTNAME}-0.3
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://hammelmann.gmxhome.de/
EXTRACT_SUFX=

MAINTAINER=	pkgsrc-users@NetBSD.org
# "MEncVCD is part of MPlayer. You can find it in subdirectory TOOLS/ of the source code."
#HOMEPAGE=	http://hammelmann.gmxhome.de/projects_en.html
COMMENT=	Script for converting movie files into (S)VCD format

DEPENDS+=	cdrdao>=1.1.9:../../sysutils/cdrdao
DEPENDS+=	lame>=3.96.1:../../audio/lame
DEPENDS+=	mjpegtools>=1.6.2:../../multimedia/mjpegtools
DEPENDS+=	mplayer>=1.0rc1:../../multimedia/mplayer
DEPENDS+=	normalize>=0.7.6:../../audio/normalize
DEPENDS+=	sox>=12.16:../../audio/sox
DEPENDS+=	vcdimager>=0.6.2:../../sysutils/vcdimager

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

REPLACE_BASH=	mencvcd
USE_TOOLS+=	bash:run

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mencvcd ${DESTDIR}${PREFIX}/bin/mencvcd

.include "../../mk/bsd.pkg.mk"
