# $NetBSD: Makefile,v 1.1.1.1 2005/12/29 15:47:43 cube Exp $
#

DISTNAME=	nsis-2.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsis/}
EXTRACT_SUFX=	.zip .tar.bz2
DISTFILES=	${DISTNAME}.zip		\
		${NSIS_SRC}.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://nsis.sourceforge.net/Main_Page
COMMENT=	Scriptable system to build Windows installers

DEPENDS+=	scons>=0.96.91:../../local/scons-devel

NSIS_SRC=	${DISTNAME:=-src}
WRKSRC=		${WRKDIR}/${NSIS_SRC}
NO_CONFIGURE=	yes
EXTRACT_CMD_OPTS.zip=	-qo

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
	        SKIPUTILS=all SKIPMISC=all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/makensis/makensis	\
	    ${MAKENSIS_BIN}
	${INSTALL_SCRIPT} ${WRKSRC}/makensis.sh ${PREFIX}/bin/makensis
	cd ${WRKDIR}/${DISTNAME} && ${FIND} . -type f | \
	    ${PAX} -rw ${PREFIX}/share/nsis

.include "../../mk/bsd.pkg.mk"
