# $NetBSD: Makefile,v 1.21 2010/01/29 20:20:53 joerg Exp $
#

DISTNAME=			aranym-0.9.6beta2
PKGREVISION=			1
CATEGORIES=			emulators
MASTER_SITES=			${MASTER_SITE_SOURCEFORGE:=aranym/}
SITES.emutos-512k-0.8.3.zip=	${MASTER_SITE_SOURCEFORGE:=emutos/}
DISTFILES=			aranym-0.9.6beta2.tar.gz emutos-512k-0.8.3.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://aranym.sourceforge.net/
COMMENT=		Atari Running on Any Machine

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake gzip
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

CONFIGURE_ARGS+=	--enable-fullmmu

EMUTOS_WRKSRC=		${WRKDIR}/emutos-512k-0.8.3
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

.if ${OPSYS} != "NetBSD" && ${OPSYS} != "DragonFly"
CONFIGURE_ARGS+=	--enable-nfpci
.endif

INSTALLATION_DIRS+=	${EMUTOS_DOC_DIR} ${EMUTOS_ROM_DIR}

post-install:
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/etos512k.img ${DESTDIR}${EMUTOS_ROM_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/readme.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/announce.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/authors.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/changelog.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/license.txt ${DESTDIR}${EMUTOS_DOC_DIR}
	${INSTALL_DATA} ${EMUTOS_WRKSRC}/doc/status.txt ${DESTDIR}${EMUTOS_DOC_DIR}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
