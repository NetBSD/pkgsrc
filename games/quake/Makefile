# $NetBSD: Makefile,v 1.2 2000/01/13 00:35:04 wiz Exp $

DISTNAME=	q1source
PKGNAME=	quake-2.30
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.cdrom.com/pub/idgames/idstuff/source/ \
		ftp://ftp.fu-berlin.de/pub/pc/msdos/games/idgames/idstuff/source/ \
		ftp://ftp.idsoftware.com/idstuff/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.idsoftware.com/

BUILD_DEPENDS+=	${UNZIP}:../../archivers/unzip
DEPENDS+=	Mesa-*:../../graphics/Mesa

USE_GMAKE=	yes

BROKEN=		untested, only compiles on a.out for now

EXTRACT_CMD=	${UNZIP} -q ${DISTDIR}/${EXTRACT_ONLY}
MAKE_ENV+=	MAINDIR=${WRKSRC}
UNZIP=		${LOCALBASE}/bin/unzip
WRKSRC=		${WRKDIR}/QW

post-extract:
	@${CHMOD} -R g-w,o-w ${WRKDIR}

do-configure:
	cd ${WRKSRC} && ${LN} -fs Makefile.Linux ${MAKEFILE}

.include "../../mk/bsd.pkg.mk"
