# $NetBSD: Makefile,v 1.173 2018/11/12 03:51:43 ryoon Exp $

DISTNAME=		mpd-0.20.21
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.musicpd.org/download/mpd/0.20/
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

# c++14
GCC_REQD+=		4.9

# MacOS X audio output is no longer enabled by default.
CONFIGURE_ARGS.Darwin+=	--enable-osx

CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mpd
CONF_FILES=		${EGDIR}/mpd.conf ${PKG_SYSCONFDIR}/mpd.conf
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	mpd.conf
SUBST_SED.paths=	-e 's,@DEVOSSAUDIO@,${DEVOSSAUDIO},'

LDFLAGS+=		${LIBOSSAUDIO}

INSTALLATION_DIRS=	${EGDIR}

post-extract:
	${CP} ${FILESDIR}/mpd.conf ${WRKSRC}/mpd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/mpd.conf ${DESTDIR}${EGDIR}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
