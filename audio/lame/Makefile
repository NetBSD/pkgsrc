# $NetBSD: Makefile,v 1.2 1999/08/10 11:16:58 agc Exp $
#

DISTNAME=	lame-3.13
CATEGORIES=	audio
MASTER_SITES=	http://hive.me.gu.edu.au/not_lame/
DISTFILES=	dist10.tar.gz.a dist10.tar.gz.b
PATCHFILES=	lame3.13.patch.gz
PATCH_SITES=	${MASTER_SITES}

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
	# ${RM} -fr ${WRKDIR}/dist10

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
