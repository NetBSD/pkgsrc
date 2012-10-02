# $NetBSD: Makefile,v 1.7 2012/10/02 23:48:08 asau Exp $
#

DISTNAME=	rtunes-snap-20071122
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nazgul.ch/dev.html
COMMENT=	Streams audio to an Apple AirPort Express device

WRKSRC=		${WRKDIR}/rtunes

NO_CONFIGURE=		yes
USE_TOOLS+=		yacc lex gmake
MAKE_FILE=		GNUmakefile

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/rtunes
CONF_FILES=		${EGDIR}/${RTUNES_CONF:T} \
				${PKG_SYSCONFDIR}/${RTUNES_CONF:T}
RTUNES_CONF=		${WRKDIR}/rtunes.conf

AUTO_MKDIRS=			yes

SUBST_CLASSES+=		doc
SUBST_FILES.doc=	librtunes/README
SUBST_STAGE.doc=	post-extract
SUBST_VARS.doc=		PREFIX

post-extract:
	cp ${FILESDIR}/${RTUNES_CONF:T} ${WRKDIR}/${RTUNES_CONF:T}

.if defined(RTUNES_SERVER) && !empty(RTUNES_SERVER)
pre-build: prepare-rtunes-conf
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtunes/rtunes \
		${DESTDIR}${PREFIX}/bin/rtunes
	${INSTALL_MAN} ${WRKSRC}/rtunes/rtunes.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/rtunes/rtunes.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/librtunes/librtunes.a \
		${DESTDIR}${PREFIX}/lib

	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/rtunes
	${INSTALL_DATA} ${WRKDIR}/rtunes.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/librtunes/mplayer.diff ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/librtunes/README \
		${DESTDIR}${PREFIX}/share/doc/rtunes

.PHONY: prepare-rtunes-conf
prepare-rtunes-conf:
	${RUN} ${ECHO_MSG} "stream to ${RTUNES_SERVER}" >> ${RTUNES_CONF:Q}

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
