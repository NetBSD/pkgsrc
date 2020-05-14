# $NetBSD: Makefile,v 1.24 2020/05/14 19:33:30 joerg Exp $

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
.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) && ${MACHINE_ARCH} == "x86_64"
CCASFLAGS+=	-fno-integrated-as
MAKE_ENV+=	AM_CCASFLAGS=${CCASFLAGS:Q}
.endif

.if ${MACHINE_ARCH} == "i386"
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
