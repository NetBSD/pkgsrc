# $NetBSD: Makefile,v 1.1.1.1 2003/09/24 10:53:27 dillo Exp $
#

DISTNAME=		arnsrc27012002
PKGNAME=		arnold-20020127
WRKSRC=			${WRKDIR}/arnold/src
CATEGORIES=		emulators
MASTER_SITES=		http://arnold.emuunlim.com/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://arnold.emuunlim.com/
COMMENT=		Amstrad CPC, Amstrad CPC+ and KC Compact emulator

# we want case sensitive file names.
EXTRACT_CMD.zip=        ${LOCALBASE}/bin/unzip -aqo $${extract_file}

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
ALL_TARGET=		arnold

SHAREDIR=		${PREFIX}/share/arnold
DOCDIR=			${PREFIX}/share/doc/arnold
MAKE_ENV+=		SHAREDIR=${SHAREDIR}

post-extract:
	${CHMOD} +x ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../arnold ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}/roms
	for dir in amsdose cpc464e cpc6128e cpc664e cpcplus kcc; \
	do \
		${INSTALL_DATA_DIR} ${SHAREDIR}/roms/$$dir; \
		for f in ${WRKSRC}/../roms/$$dir/*; \
		do \
			${INSTALL_DATA} $$f ${SHAREDIR}/roms/$$dir; \
		done \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/../readme.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/../readme.linux ${DOCDIR}

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
