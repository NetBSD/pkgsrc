# $NetBSD: Makefile,v 1.23 2019/11/03 10:39:21 rillig Exp $
#

DISTNAME=	nsis-${NSIS_VER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsis/}
EXTRACT_SUFX=	.zip .tar.bz2
DISTFILES=	${DISTNAME}.zip		\
		${NSIS_SRC}.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nsis.sourceforge.net/Main_Page
COMMENT=	Scriptable system to build Windows installers

USE_LANGUAGES=	c c++
USE_TOOLS+=	pax

PYTHON_VERSIONS_ACCEPTED=	27	# as of 3.04

NSIS_SRC=		${DISTNAME:=-src}
NSIS_VER=		3.04
WRKSRC=			${WRKDIR}/${NSIS_SRC}
NO_CONFIGURE=		yes
EXTRACT_OPTS_ZIP=	-qo

MAKENSIS_BIN=	${PREFIX}/share/nsis/makensis

INSTALLATION_DIRS=	bin share/nsis

SUBST_CLASSES+=		makensis
SUBST_STAGE.makensis=	pre-build
SUBST_FILES.makensis=	makensis.sh
SUBST_SED.makensis=	-e s,@@SH@@,${SH:Q},
SUBST_SED.makensis+=	-e s,@@MAKENSIS@@,${MAKENSIS_BIN:Q},

post-extract:
	${CP} ${FILESDIR:Q}/makensis.sh ${WRKSRC:Q}
	chmod -R go-w ${WRKDIR}/*

do-build:
	cd ${WRKSRC:Q} && ${PKGSRC_SETENV} ${MAKE_ENV}			\
	    ${SCONSBIN:Q} SKIPSTUBS=all SKIPPLUGINS=all		\
	        SKIPUTILS=all SKIPMISC=all VERSION=${NSIS_VER:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/build/urelease/makensis/makensis	\
		${DESTDIR}${MAKENSIS_BIN:Q}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/makensis.sh			\
		${DESTDIR}${PREFIX:Q}/bin/makensis
	cd ${WRKDIR:Q}/${DISTNAME:Q} && pax -rw .			\
		${DESTDIR}${PREFIX:Q}/share/nsis

.include "../../devel/scons/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
