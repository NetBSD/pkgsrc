# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=		pearpc-0.3.1
PKGREVISION=	1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pearpc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pearpc.sourceforge.net/
COMMENT=		PowerPC emulator

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LANGUAGES+=		c++
USE_PKGINSTALL=		yes
USE_X11=		yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ppccfg.example ${PKG_SYSCONFDIR}/ppccfg.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:Mi386)
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
CONFIGURE_ARGS+=	--enable-cpu=jitc_x86
.endif

CONFIGURE_ARGS+=	--disable-debug

INSTALLATION_DIRS=	share/${PKGBASE} bin

do-install:
	${SED}	-e "s,@PREFIX@,${PREFIX}," \
		-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR}," \
		${FILESDIR}/pearpc.sh > ${WRKSRC}/pearpc.sh
	${INSTALL_SCRIPT} ${WRKSRC}/pearpc.sh ${PREFIX}/bin/pearpc
	${INSTALL_PROGRAM} ${WRKSRC}/src/ppc ${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/video.x ${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${EGDIR}

SUBST_CLASSES=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	ppccfg.example
SUBST_SED.conf=		-e "s|\"nvram\"|\"/tmp/nvram\"|"
SUBST_MESSAGE.conf=	"Fixing configuration file."

PKG_OPTIONS_VAR=	PKG_OPTIONS.pearpc
PKG_SUPPORTED_OPTIONS=	sdl

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-ui=x11
.else
CONFIGURE_ARGS+=	--enable-ui=sdl
.  include "../../devel/SDL/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
