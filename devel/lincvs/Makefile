# $NetBSD: Makefile,v 1.15 2013/04/13 07:55:01 ghen Exp $

DISTNAME=		lincvs-1.4.4-0-generic-src
PKGNAME=		${DISTNAME:S/-0-generic-src//}
PKGREVISION=		3
CATEGORIES=		devel x11 scm
MASTER_SITES=		http://lincvs.com/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
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
AUTO_MKDIRS=			yes

do-configure:
	cd ${WRKSRC} && qmake -o Makefile lincvs.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lincvs.bin ${DESTDIR}${PREFIX}/bin/lincvs
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/rshwrapper/rshwrapper ${DESTDIR}${PREFIX}/libexec/rshwrapper
	cd ${WRKSRC}/doc && ${INSTALL_DATA} FAM-HOWTO.txt FAQ.txt INFO.txt INSTALL INSTALL.html PROXY-HOWTO.txt README README.html SSH-HOWTO.txt ${DESTDIR}${PREFIX}/share/doc/lincvs/
.for lang in de it ru
	cd ${WRKSRC}/doc/translations/${lang} && ${INSTALL_DATA} * ${DESTDIR}${PREFIX}/share/doc/lincvs/${lang}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/ts/*.qm ${DESTDIR}${PREFIX}/share/lincvs/messages/

.include "../../x11/qt3/application.mk"
.include "../../mk/bsd.pkg.mk"
