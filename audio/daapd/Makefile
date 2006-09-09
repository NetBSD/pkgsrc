# $NetBSD: Makefile,v 1.23 2006/09/09 02:41:54 obache Exp $

DISTNAME=		daapd-0.2.4b
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.deleet.de/projekte/daap/daapd/
COMMENT=		Server for DAA protocol (iTunes)

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FILE=		makefile

RCD_SCRIPTS=		daapd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/daapd.conf ${PKG_SYSCONFDIR}/daapd.conf

PKG_OPTIONS_VAR=PKG_OPTIONS.daapd
PKG_SUPPORTED_OPTIONS=mpeg4ip
# to be removed after 2006Q2
PKG_OPTIONS_LEGACY_OPTS+=faad:mpeg4ip
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.include "../../multimedia/mpeg4ip/buildlink3.mk"
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

post-extract:
	for FILE in `${FIND} ${WRKSRC}/daaplib -type f -print`; do	\
	  ${TR} -d \\r <$${FILE} >$${FILE}.new;				\
	  ${MV} $${FILE}.new $${FILE};					\
	done

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/daapd-example.conf ${EGDIR}/daapd.conf

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
