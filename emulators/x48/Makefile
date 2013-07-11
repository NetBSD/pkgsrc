# $NetBSD: Makefile,v 1.18 2013/07/11 13:15:57 wiz Exp $

DISTNAME=	x48-0.6.4
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=x48.berlios/}
DISTFILES=	${PKGNAME_NOREV}${EXTRACT_SUFX}
DISTFILES+=	sxrom-e.bz2 gxrom-r.bz2
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://x48.berlios.de/
COMMENT=	HP48 emulator
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}
#USE_IMAKE=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config aclocal autoconf automake autoreconf
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

DATADIR=	lib/x48
APPDEFS=	lib/X11/app-defaults

INSTALLATION_DIRS+=	share/doc/x48/romdump
INSTALLATION_DIRS+=	${DATADIR}
INSTALLATION_DIRS+=	${APPDEFS}

CONFIGURE_ARGS=	--disable-shm

CPPFLAGS+=	-DHAVE_STDLIB
CPPFLAGS+=	-DX11APPDEFS=\"${PREFIX}/${APPDEFS}\"

SUBST_CLASSES=	fix-ad
SUBST_STAGE.fix-ad=	post-configure
SUBST_MESSAGE.fix-ad=	Fix default rom path
SUBST_FILES.fix-ad=	src/X48.ad
SUBST_SED.fix-ad=	-e 's,rom.dump,${PREFIX}/${DATADIR}/gxrom-r,'


pre-configure:
	cd ${WRKSRC} && autoreconf -fi

post-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} X48 \
			${DESTDIR}${PREFIX}/lib/X11/app-defaults
	cd ${WRKSRC} && \
		${INSTALL_DATA} ??rom-? ${DESTDIR}${PREFIX}/${DATADIR}
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} CARDS.doc INSTALLING ROMDump.doc \
			${DESTDIR}${PREFIX}/share/doc/x48
	cd ${WRKSRC}/romdump && \
		${INSTALL_MAN} README ${DESTDIR}${PREFIX}/share/doc/x48/romdump && \
		${INSTALL_DATA} ROMDump ROMDump.s \
			${DESTDIR}${PREFIX}/share/doc/x48/romdump

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
