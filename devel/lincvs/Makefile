# $NetBSD: Makefile,v 1.8 2006/08/22 15:20:02 joerg Exp $

DISTNAME=		lincvs-1.4.4-0-generic-src
PKGNAME=		${DISTNAME:S/-0-generic-src//}
PKGREVISION=		3
CATEGORIES=		devel x11
MASTER_SITES=	        http://lincvs.com/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://lincvs.org/
COMMENT=		Nice GUI front-end to CVS (using Qt)

USE_LANGUAGES=		c c++

SUBST_CLASSES+=		qmake
SUBST_STAGE.qmake=	post-patch
SUBST_FILES.qmake=	lincvs.pro
SUBST_SED.qmake=	-e 's,%%QTDIR%%,${QTDIR},'

SUBST_CLASSES+=		appdir
SUBST_STAGE.appdir=	post-patch
SUBST_FILES.appdir=	src/lincvs.cpp src/main.cpp src/cvscontrol.cpp
SUBST_SED.appdir=	-e 's,%%PREFIX%%,${PREFIX},'

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

do-configure:
	 ${QTDIR}/bin/qmake -o ${WRKSRC}/Makefile ${WRKSRC}/lincvs.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lincvs.bin ${PREFIX}/bin/lincvs
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/rshwrapper/rshwrapper ${PREFIX}/libexec/rshwrapper
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lincvs
.for FILE in FAM-HOWTO.txt FAQ.txt INFO.txt INSTALL INSTALL.html PROXY-HOWTO.txt README README.html SSH-HOWTO.txt
		${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${PREFIX}/share/doc/lincvs/
.endfor
.for LANG in de it ru
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lincvs/${LANG}
		${INSTALL_DATA} ${WRKSRC}/doc/translations/${LANG}/* ${PREFIX}/share/doc/lincvs/${LANG}/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincvs/messages
	${INSTALL_DATA} ${WRKSRC}/ts/*.qm ${PREFIX}/share/lincvs/messages/

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
