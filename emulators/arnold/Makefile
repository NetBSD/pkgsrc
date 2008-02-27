# $NetBSD: Makefile,v 1.17 2008/02/27 12:52:41 rillig Exp $
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
MAKE_FLAGS+=		LFLAGS2=#none, especially not -s

SHAREDIR=		${PREFIX}/share/arnold
MAKE_ENV+=		SHAREDIR=${SHAREDIR}
AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arnold ${PREFIX}/bin
	cd ${WRKSRC}/roms && pax -wr * ${SHAREDIR}/roms/
	cd ${WRKSRC} && ${INSTALL_DATA} readme.* ${PREFIX}/share/doc/arnold

.include "../../mk/oss.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
