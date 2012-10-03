# $NetBSD: Makefile,v 1.26 2012/10/03 12:55:09 asau Exp $
#

DISTNAME=			aranym_0.9.13.orig
PKGNAME=			${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=			2
CATEGORIES=			emulators
MASTER_SITES=			${MASTER_SITE_SOURCEFORGE:=aranym/}
SITES.emutos-512k-0.8.6.zip=	${MASTER_SITE_SOURCEFORGE:=emutos/}
DISTFILES=			${DEFAULT_DISTFILES} emutos-512k-0.8.6.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://aranym.sourceforge.net/
COMMENT=		Atari Running on Any Machine
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

AUTOCONF_REQD=		2..50

USE_TOOLS+=		autoconf gmake gzip
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

CONFIGURE_ARGS+=	--enable-fullmmu
CONFIGURE_ARGS+=	--enable-atc=full

EMUTOS_WRKSRC=		${WRKDIR}/emutos-512k-0.8.6
EMUTOS_DOC_DIR=		${PREFIX}/share/doc/aranym/emutos
EMUTOS_ROM_DIR=		${PREFIX}/share/aranym

REQD_DIRS+=		${EMUTOS_ROM_DIR} ${EMUTOS_DOC_DIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths=	doc/config
SUBST_FILES.paths+=	doc/aranym.1
SUBST_SED.paths=	-e "s|/usr/share/|${PREFIX}/share/|g"
SUBST_SED.paths+=	-e "s|/usr/local/share/|${PREFIX}/share/|g"
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-nfpci
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-i386)
CONFIGURE_ARGS+=	--enable-jit-compiler
CONFIGURE_ARGS+=	--enable-jit-fpu
.endif

# This appears if it thinks it can use tun/tap interfaces.
# (While NetBSD has these, the configure test rejects it.)
PLIST_VARS+=		aratapif
.if !empty(MACHINE_PLATFORM:MLinux-*-*) || \
	!empty(MACHINE_PLATFORM:MDarwin-*-*)
PLIST.aratapif=		yes
.endif

INSTALLATION_DIRS+=	${EMUTOS_DOC_DIR} ${EMUTOS_ROM_DIR}

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/etos512k.img ${DESTDIR}${EMUTOS_ROM_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/readme.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/announce.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/authors.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/changelog.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/license.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/status.txt ${DESTDIR}${EMUTOS_DOC_DIR}

.include "../../devel/SDL/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
