# $NetBSD: Makefile,v 1.7 2006/02/15 17:27:19 rillig Exp $
#

DISTNAME=	nsis-${NSIS_VER}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsis/}
EXTRACT_SUFX=	.zip .tar.bz2
DISTFILES=	${DISTNAME}.zip		\
		${NSIS_SRC}.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://nsis.sourceforge.net/Main_Page
COMMENT=	Scriptable system to build Windows installers

DEPENDS+=	scons>=0.96.91:../../devel/scons-devel

NSIS_SRC=	${DISTNAME:=-src}
NSIS_VER=	2.12
WRKSRC=		${WRKDIR}/${NSIS_SRC}
NO_CONFIGURE=	yes
EXTRACT_OPTS_ZIP=	-qo

EVAL_PREFIX+=	SCONS_PREFIX=scons
SCONS_BIN=	${SCONS_PREFIX}/bin/scons
MAKENSIS_BIN=	${PREFIX}/share/nsis/makensis

INSTALLATION_DIRS=	bin share/nsis

SUBST_CLASSES+=		makensis
SUBST_STAGE.makensis=	post-patch
SUBST_FILES.makensis=	makensis.sh
SUBST_SED.makensis=	-e s,@@SH@@,${SH:Q}, \
			-e s,@@MAKENSIS@@,${MAKENSIS_BIN:Q},

post-extract:
	${CP} ${FILESDIR:Q}/makensis.sh ${WRKSRC:Q}

do-build:
	cd ${WRKSRC:Q} &&						\
	    ${SCONS_BIN:Q} SKIPSTUBS=all SKIPPLUGINS=all		\
	        SKIPUTILS=all SKIPMISC=all VERSION=${NSIS_VER:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/build/release/makensis/makensis	\
	    ${MAKENSIS_BIN:Q}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/makensis.sh ${PREFIX:Q}/bin/makensis
	cd ${WRKDIR:Q}/${DISTNAME:Q} && ${PAX} -rw . ${PREFIX:Q}/share/nsis

.include "../../mk/bsd.pkg.mk"
