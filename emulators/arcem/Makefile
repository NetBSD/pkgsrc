# $NetBSD: Makefile,v 1.27 2020/03/20 11:57:35 nia Exp $
#

DISTNAME=	arcem-1.50-src
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arcem/}
EXTRACT_SUFX=	.zip

LINUX_FILES=	\
		linux.rom.gz \
		HardImage1.gz

.for f in ${LINUX_FILES}
SITES.${f}+=	\
		ftp://ftp.arm.uk.linux.org/pub/linux/arcem/
.endfor

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LINUX_FILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arcem.sourceforge.net/
COMMENT=	Dave Gilbert's Acorn Archimedes emulator

WRKSRC=		${WRKDIR}/arcem-src
USE_TOOLS+=	gmake

MAKE_ENV+=	SYSTEM=X

INSTALLATION_DIRS+=	bin share/arcem

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arcem ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/linux.rom \
		${DESTDIR}${PREFIX}/share/arcem/ROM
	${INSTALL_DATA} ${WRKDIR}/HardImage1 \
		${DESTDIR}${PREFIX}/share/arcem/HardImage1
	${INSTALL_DATA} ${FILESDIR}/dot.arcemrc \
		${DESTDIR}${PREFIX}/share/arcem/dot.arcemrc
	${INSTALL_DATA} ${WRKSRC}/hexcmos \
		${DESTDIR}${PREFIX}/share/arcem/hexcmos
	${INSTALL_DATA} ${WRKSRC}/support_modules/hostfs/hostfs,ffa \
		${DESTDIR}${PREFIX}/share/arcem/hostfs,ffa
	${INSTALL_DATA} ${WRKSRC}/support_modules/hostfs/hostfsfiler,ffa \
		${DESTDIR}${PREFIX}/share/arcem/hostfsfiler,ffa
	${INSTALL_DATA} ${WRKSRC}/support_modules/modes/ArcemModes,ffa \
		${DESTDIR}${PREFIX}/share/arcem/ArcemModes,ffa
	${INSTALL_DATA} ${WRKSRC}/support_modules/modes/MakeModes,ffb \
		${DESTDIR}${PREFIX}/share/arcem/MakeModes,ffb
	${INSTALL_DATA} ${WRKSRC}/support_modules/modes/ModeGen,ffb \
		${DESTDIR}${PREFIX}/share/arcem/ModeGen,ffb
	${INSTALL_DATA} ${WRKSRC}/support_modules/modes/README \
		${DESTDIR}${PREFIX}/share/arcem/README.Modes
	${INSTALL_DATA} ${WRKSRC}/support_modules/scrollwheel/scrollwheel,ffa \
		${DESTDIR}${PREFIX}/share/arcem/scrollwheel,ffa
	${INSTALL_DATA} ${WRKSRC}/support_modules/support/support,ffa \
		${DESTDIR}${PREFIX}/share/arcem/support,ffa

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
