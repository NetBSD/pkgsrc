# $NetBSD: Makefile,v 1.12 2004/11/25 20:16:52 xtraeme Exp $

DISTNAME=		mpd-0.11.5
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
CATEGORIES=		audio
MASTER_SITES=		http://mercury.chem.pitt.edu/~shank/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Remote controllable audio player

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/mpd
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO}
LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	src/main.c
SUBST_SED.config=	-e s,/etc/mpd.conf,${PKG_SYSCONFDIR}/mpd.conf,

# when IPv6 support is enabled, mpd doesn't listen on an IPv4 address.
#.if defined(USE_INET6) && ${USE_INET6} == "YES"
#CONFIGURE_ARGS+=	--enable-ipv6
#.else
CONFIGURE_ARGS+=	--disable-ipv6
#.endif

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mpd.conf > ${WRKDIR}/mpd.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mpd.conf ${EGDIR}

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
