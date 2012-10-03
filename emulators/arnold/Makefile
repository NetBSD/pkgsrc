# $NetBSD: Makefile,v 1.25 2012/10/03 12:55:10 asau Exp $
#

DISTNAME=		arnsrc27012002
PKGNAME=		arnold-20020127
PKGREVISION=		6
CATEGORIES=		emulators
MASTER_SITES=		http://arnold.emuunlim.com/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://arnold.emuunlim.com/
COMMENT=		Amstrad CPC, Amstrad CPC+ and KC Compact emulator

WRKSRC=			${WRKDIR}/arnold
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
BUILD_DIRS=		${CONFIGURE_DIRS}
BUILD_TARGET=		arnold
MAKE_FLAGS+=		LFLAGS2=#none, especially not -s

SHAREDIR=		${PREFIX}/share/arnold
MAKE_ENV+=		SHAREDIR=${SHAREDIR}
AUTO_MKDIRS=		yes

USE_TOOLS+=		pax

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arnold ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/roms && pax -wr * ${DESTDIR}${SHAREDIR}/roms/
	cd ${DESTDIR}${SHAREDIR}/roms && \
		${FIND} . -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE} && \
		${FIND} . -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	cd ${WRKSRC} && ${INSTALL_DATA} readme.* \
		${DESTDIR}${PREFIX}/share/doc/arnold

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX}/lib
.endif

.include "../../mk/oss.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
