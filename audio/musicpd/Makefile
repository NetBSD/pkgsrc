# $NetBSD: Makefile,v 1.80 2014/05/05 00:47:37 ryoon Exp $

DISTNAME=		mpd-0.18.10
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.musicpd.org/download/mpd/0.18/
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Remote controllable audio player
LICENSE=		gnu-gpl-v2

CONFLICTS=		mpd-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

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

INSTALLATION_DIRS=	${EGDIR}

post-extract:
	${CP} ${FILESDIR}/mpd.conf ${WRKSRC}/mpd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/mpd.conf ${DESTDIR}${EGDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
