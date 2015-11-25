# $NetBSD: Makefile,v 1.17 2015/11/25 12:49:46 jperkin Exp $
#

DISTNAME=	nsis-${NSIS_VER}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsis/}
EXTRACT_SUFX=	.zip .tar.bz2
DISTFILES=	${DISTNAME}.zip		\
		${NSIS_SRC}.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nsis.sourceforge.net/Main_Page
COMMENT=	Scriptable system to build Windows installers

DEPENDS+=	scons>=0.96.91:../../devel/scons

USE_LANGUAGES=	c c++
USE_TOOLS+=	pax

NSIS_SRC=	${DISTNAME:=-src}
NSIS_VER=	2.12
WRKSRC=		${WRKDIR}/${NSIS_SRC}
NO_CONFIGURE=	yes
EXTRACT_OPTS_ZIP=	-qo

SCONS_BIN=	${LOCALBASE}/bin/scons
MAKENSIS_BIN=	${PREFIX}/share/nsis/makensis

INSTALLATION_DIRS=	bin share/nsis

SUBST_CLASSES+=		makensis
SUBST_STAGE.makensis=	post-patch
SUBST_FILES.makensis=	makensis.sh
SUBST_SED.makensis=	-e s,@@SH@@,${SH:Q},
SUBST_SED.makensis+=	-e s,@@MAKENSIS@@,${MAKENSIS_BIN:Q},

post-extract:
	${CP} ${FILESDIR:Q}/makensis.sh ${WRKSRC:Q}
	chmod -R go-w ${WRKDIR}/*

do-build:
	cd ${WRKSRC:Q} && ${PKGSRC_SETENV} ${MAKE_ENV}			\
	    ${SCONS_BIN:Q} SKIPSTUBS=all SKIPPLUGINS=all		\
	        SKIPUTILS=all SKIPMISC=all VERSION=${NSIS_VER:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/build/release/makensis/makensis	\
		${DESTDIR}${MAKENSIS_BIN:Q}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/makensis.sh			\
		${DESTDIR}${PREFIX:Q}/bin/makensis
	cd ${WRKDIR:Q}/${DISTNAME:Q} && pax -rw .			\
		${DESTDIR}${PREFIX:Q}/share/nsis

.include "../../mk/bsd.pkg.mk"
