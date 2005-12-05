# $NetBSD: Makefile,v 1.20 2005/12/05 20:49:49 rillig Exp $

DISTNAME=		mpd-0.11.5
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		http://mercury.chem.pitt.edu/~shank/

CONFLICTS=		mpd-[0-9]*

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Remote controllable audio player

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mpd
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	src/main.c
SUBST_SED.config=	-e s,/etc/mpd.conf,${PKG_SYSCONFDIR}/mpd.conf,

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mpd.conf > ${WRKDIR}/mpd.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mpd.conf ${EGDIR}

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
