# $NetBSD: Makefile,v 1.33 2009/01/20 22:52:17 drochner Exp $

DISTNAME=		mpd-0.14.1
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
CATEGORIES=		audio
#MASTER_SITES=		http://musicpd.org/uploads/files/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=		.tar.bz2

CONFLICTS=		mpd-[0-9]*

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Remote controllable audio player

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mpd
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		config paths
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	src/main.c
SUBST_SED.config=	-e s,/etc/mpd.conf,${PKG_SYSCONFDIR}/mpd.conf,
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	mpd.conf
SUBST_SED.paths=	-e 's,@DEVOSSAUDIO@,${DEVOSSAUDIO},'

post-extract:
	${CP} ${FILESDIR}/mpd.conf ${WRKSRC}/mpd.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mpd.conf ${EGDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
