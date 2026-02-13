# $NetBSD: Makefile,v 1.1 2026/02/13 15:09:13 nia Exp $

DISTNAME=	ElkulatorV1.0Linux
PKGNAME=	elkulator-1.0
CATEGORIES=	emulators
MASTER_SITES=	https://www.elkulator.acornelectron.co.uk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.elkulator.acornelectron.co.uk/
COMMENT=	Freeware Acorn Electron emulator
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}

USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	pax

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-allegrotest

LIBS+=			-lm # fmodf, sin...

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/${PKGBASE}/roms

pre-patch:
	find ${WRKSRC} -name "*.c" -type f | xargs dos2unix
	find ${WRKSRC} -name "*.h" -type f | xargs dos2unix

pre-configure:
	cd ${WRKSRC} && autoreconf -fi
	${SED}	-e 's,@PREFIX@,${PREFIX},g' \
		< ${FILESDIR}/elkulator.sh.in > \
		${WRKDIR}/elkulator.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PKGBASE} \
		${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE}.sh \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/elk.cfg \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/icon/${PKGBASE}.png \
		${DESTDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${FILESDIR}/${PKGBASE}.desktop \
		${DESTDIR}${PREFIX}/share/applications/
	cd ${WRKSRC}/roms && ${PAX} -rw -pp . \
		${DESTDIR}${PREFIX}/share/elkulator/roms

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
