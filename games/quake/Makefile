# $NetBSD: Makefile,v 1.1.1.1 1999/12/28 14:20:41 tron Exp $

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

BROKEN=		more patches are needed to make it build.

EXTRACT_CMD=	${UNZIP} -q ${DISTDIR}/${EXTRACT_ONLY}
MAKE_ENV+=	MAINDIR=${WRKSRC}
UNZIP=		${LOCALBASE}/bin/unzip
WRKSRC=		${WRKDIR}/QW

post-extract:
	@${CHMOD} -R g-w,o-w ${WRKDIR}

do-configure:
	cd ${WRKSRC} && ${LN} -fs Makefile.Linux ${MAKEFILE}

.include "../../mk/bsd.pkg.mk"
