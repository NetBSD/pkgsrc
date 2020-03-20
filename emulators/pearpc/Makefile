# $NetBSD: Makefile,v 1.23 2020/03/20 11:57:36 nia Exp $

DISTNAME=		pearpc-0.5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pearpc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pearpc.sourceforge.net/
COMMENT=		PowerPC emulator

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++03

BUILDLINK_TRANSFORM+=	rm:-Wall

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ppccfg.example ${PKG_SYSCONFDIR}/ppccfg.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:Mi386)
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
CONFIGURE_ARGS+=	--enable-cpu=jitc_x86
.endif

CONFIGURE_ARGS+=	--disable-debug

INSTALLATION_DIRS=	share/${PKGBASE} ${EGDIR} bin

NOT_PAX_MPROTECT_SAFE+=	share/pearpc/ppc

do-install:
	${SED}	-e "s,@PREFIX@,${PREFIX}," \
		-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR}," \
		${FILESDIR}/pearpc.sh > ${WRKSRC}/pearpc.sh
	${INSTALL_SCRIPT} ${WRKSRC}/pearpc.sh ${DESTDIR}${PREFIX}/bin/pearpc
	${INSTALL_PROGRAM} ${WRKSRC}/src/ppc ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/video.x ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${DESTDIR}${EGDIR}

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	ppccfg.example
SUBST_SED.conf=		-e "s|\"nvram\"|\"/tmp/nvram\"|"
SUBST_MESSAGE.conf=	Fixing configuration file.

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
