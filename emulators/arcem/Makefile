# $NetBSD: Makefile,v 1.20 2012/10/03 12:55:10 asau Exp $
#

DISTNAME=	arcem-1.00-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arcem/}

NOT_FOR_PLATFORM+=	${LP64PLATFORMS}

EXTRACT_SUFX=	.tgz

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

WRKSRC=		${WRKDIR}/arcem
USE_TOOLS+=	gmake

MAKE_ENV+=	SYSTEM=X

INSTALLATION_DIRS+=	bin share/arcem

post-install:
	${INSTALL_DATA} ${WRKDIR}/linux.rom \
		${DESTDIR}${PREFIX}/share/arcem/ROM
	${INSTALL_DATA} ${WRKDIR}/HardImage1 \
		${DESTDIR}${PREFIX}/share/arcem/HardImage1
	${INSTALL_DATA} ${FILESDIR}/dot.arcemrc \
		${DESTDIR}${PREFIX}/share/arcem/dot.arcemrc
	${INSTALL_DATA} ${WRKSRC}/hexcmos \
		${DESTDIR}${PREFIX}/share/arcem/hexcmos

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
