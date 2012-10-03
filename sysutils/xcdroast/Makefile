# $NetBSD: Makefile,v 1.62.2.1 2012/10/03 12:09:33 spz Exp $

DISTNAME=	xcdroast-${DIST_VER}
PKGNAME=	xcdroast-${DIST_VER:S/alpha/a/}
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

PATCH_SITES=	http://www.xcdroast.org/xcdr098/patches/
PATCHFILES=	parse_version.patch

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	Graphical user interface for the command-line cdrecord-tools

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		cdrtools>=2.01:../../sysutils/cdrtools

DIST_VER=		0.98alpha16

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
CFLAGS+=	-DHAVE_OSS
CONFIGURE_ENV+=	AUDIO_LIBS=${LIBOSSAUDIO}
.endif

DOCDIR=		${PREFIX}/share/doc/xcdroast
DOCFILES=	DOCUMENTATION FAQ README.nonroot manual/xcdroast-manual.pdf
HTMLDIR=	${PREFIX}/share/doc/html/xcdroast
CONF_FILES=	/dev/null ${PKG_SYSCONFDIR}/xcdroast.conf

SUBST_CLASSES+=			devossaudio
SUBST_STAGE.devossaudio=	pre-build
SUBST_MESSAGE.devossaudio=	Fixing path to audio device.
SUBST_FILES.devossaudio=	io.c wavplay.c
SUBST_SED.devossaudio=		-e "s,@DEVOSSAUDIO@,${DEVOSSAUDIO},g"

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	(cd ${WRKSRC}/doc;						\
	for file in ${DOCFILES}; do	\
		${INSTALL_DATA} $${file} ${DESTDIR}${DOCDIR};		\
	done)

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
