# $NetBSD: Makefile,v 1.39 2009/08/10 23:10:29 tnn Exp $

DISTNAME=		mpd-0.15.1
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
PKGREVISION=		1
CATEGORIES=		audio
#MASTER_SITES=		http://musicpd.org/uploads/files/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=		.tar.bz2

CONFLICTS=		mpd-[0-9]*

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Remote controllable audio player

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mpd
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		config paths
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	src/cmdline.c
SUBST_SED.config=	-e s,/etc/mpd.conf,${PKG_SYSCONFDIR}/mpd.conf,
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	mpd.conf
SUBST_SED.paths=	-e 's,@DEVOSSAUDIO@,${DEVOSSAUDIO},'

post-extract:
	${CP} ${FILESDIR}/mpd.conf ${WRKSRC}/mpd.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mpd.conf ${DESTDIR}${EGDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
