# $NetBSD: Makefile,v 1.3 1999/09/27 14:17:22 agc Exp $
#

DISTNAME=	lame-3.13
CATEGORIES=	audio
MASTER_SITES=	http://hive.me.gu.edu.au/not_lame/
DISTFILES=	dist10.tar.gz.a dist10.tar.gz.b lame3.13.patch.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hive.me.gu.edu.au/not_lame/

DIST_SUBDIR=	notlame
EXTRACT_ONLY=
WRKSRC=		${WRKDIR}/lame_src
PATCH_DIST_STRIP= -p1
USE_GMAKE=	yes
ALL_TARGET=	lame
MIRROR_DISTFILE=no
LICENSE=	fee-based-commercial-use

post-extract:
	${CAT} ${_DISTDIR}/dist* | ( cd ${WRKDIR} ; ${GTAR} plzxf - )
	${MV} ${WRKDIR}/dist10/lsf/encoder ${WRKSRC}
	cd ${WRKDIR}; ${GTAR} xvzf ${_DISTDIR}/lame3.13.patch.tgz
	cd ${WRKSRC}; ${PATCH} -p1 < ${WRKDIR}/lame3.13.patch
	# ${RM} -fr ${WRKDIR}/dist10

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
