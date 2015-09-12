# $NetBSD: Makefile,v 1.1 2015/09/12 18:53:17 wiz Exp $

DISTNAME=	teeworlds-0.6.3-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	http://downloads.teeworlds.com/

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	http://www.teeworlds.com/
COMMENT=	Fast-paced retro multiplayer shooter
LICENSE=	zlib AND 2-clause-bsd AND modified-bsd AND cc-by-sa-v3.0

USE_LANGUAGES=	c c++

BUILD_DEPENDS+= bam>=0.4.0:../../devel/bam

AUTO_MKDIRS=	yes

CPIO=	cpio

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # hardcoded to 2.7 in a patch

do-configure:
	set -e; cd ${WRKSRC}; bam config

do-build:
	set -e; cd ${WRKSRC}; bam server_release client_release

do-install:
	${INSTALL_GAME} ${WRKSRC}/teeworlds ${DESTDIR}${PREFIX}/bin/teeworlds
	${INSTALL_GAME} ${WRKSRC}/teeworlds_srv ${DESTDIR}${PREFIX}/bin/teeworlds_srv
	cd ${WRKSRC} && ${FIND} data | \
		${CPIO} -p ${DESTDIR}${PREFIX}/share/teeworlds
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/teeworlds -type f -print >${WRKDIR}/PLIST

.include "../../devel/SDL/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
