# $NetBSD: Makefile,v 1.4 2006/01/20 23:41:29 jlam Exp $
#

DISTNAME=	nsis-${NSIS_VER}
PKGREVISION=	1
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
SUBST_SED.makensis=	-e s,@@SH@@,${SH}, \
			-e s,@@MAKENSIS@@,${MAKENSIS_BIN},

post-extract:
	${CP} ${FILESDIR}/makensis.sh ${WRKSRC}

do-build:
	cd ${WRKSRC} &&					\
	    ${SCONS_BIN} SKIPSTUBS=all SKIPPLUGINS=all	\
	        SKIPUTILS=all SKIPMISC=all VERSION=${NSIS_VER}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/makensis/makensis	\
	    ${MAKENSIS_BIN}
	${INSTALL_SCRIPT} ${WRKSRC}/makensis.sh ${PREFIX}/bin/makensis
	cd ${WRKDIR}/${DISTNAME} && ${FIND} . -type f | \
	    ${PAX} -rw ${PREFIX}/share/nsis

.include "../../mk/bsd.pkg.mk"
