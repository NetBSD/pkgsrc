# $NetBSD: Makefile,v 1.16 2006/06/12 16:28:06 wiz Exp $
#

DISTNAME=		arnsrc27012002
PKGNAME=		arnold-20020127
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		http://arnold.emuunlim.com/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://arnold.emuunlim.com/
COMMENT=		Amstrad CPC, Amstrad CPC+ and KC Compact emulator

# we want case sensitive file names.
EXTRACT_OPTS_ZIP=	-aqo

WRKSRC=			${WRKDIR}/arnold
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
BUILD_DIRS=		${CONFIGURE_DIRS}
BUILD_TARGET=		arnold

SHAREDIR=		${PREFIX}/share/arnold
DOCDIR=			${PREFIX}/share/doc/arnold
MAKE_ENV+=		SHAREDIR=${SHAREDIR:Q}
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arnold ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}/roms
	for dir in amsdose cpc464e cpc6128e cpc664e cpcplus kcc; \
	do \
		${INSTALL_DATA_DIR} ${SHAREDIR}/roms/$$dir; \
		for f in ${WRKSRC}/roms/$$dir/*; \
		do \
			${INSTALL_DATA} $$f ${SHAREDIR}/roms/$$dir; \
		done \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.linux ${DOCDIR}

.include "../../mk/oss.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
