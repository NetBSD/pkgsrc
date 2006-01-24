# $NetBSD: Makefile,v 1.15 2006/01/24 15:18:38 tonio Exp $

DISTNAME=		daapd-0.2.4a
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.deleet.de/projekte/daap/daapd/
COMMENT=		Server for DAA protocol (iTunes)

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKEFILE=		makefile

RCD_SCRIPTS=		daapd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=    		${EGDIR}/daapd.conf ${PKG_SYSCONFDIR}/daapd.conf

PKG_OPTIONS_VAR=PKG_OPTIONS.daapd
PKG_SUPPORTED_OPTIONS=faad
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfaad)
.include "../../audio/faad2/buildlink3.mk"
MAKE_ENV+= WITH_FAAD=1
.else
MAKE_ENV+= WITH_FAAD=0
.endif

MAKE_ENV+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	daapd.8 daapd.cc
SUBST_SED.paths=	-e 's,/etc/,${PKG_SYSCONFDIR}/,g'

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/daapd-example.conf ${EGDIR}/daapd.conf

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
