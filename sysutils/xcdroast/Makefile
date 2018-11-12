# $NetBSD: Makefile,v 1.80 2018/11/12 03:52:57 ryoon Exp $

DISTNAME=	xcdroast-1.18
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	Graphical user interface for the command-line cdrecord-tools
LICENSE=	gnu-gpl-v2

DEPENDS+=		cdrtools>=2.01:../../sysutils/cdrtools

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
CONF_FILES=	/dev/null ${PKG_SYSCONFDIR}/xcdroast.conf

SUBST_CLASSES+=			devossaudio
SUBST_STAGE.devossaudio=	pre-build
SUBST_MESSAGE.devossaudio=	Fixing path to audio device.
SUBST_FILES.devossaudio=	io.c wavplay.c
SUBST_SED.devossaudio=		-e "s,@DEVOSSAUDIO@,${DEVOSSAUDIO},g"

INSTALLATION_DIRS=	${DOCDIR}
SPECIAL_PERMS+=		lib/xcdroast/bin/xcdrwrap {REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4711

post-install:
	(cd ${WRKSRC}/doc;						\
	for file in ${DOCFILES}; do	\
		${INSTALL_DATA} $${file} ${DESTDIR}${DOCDIR};		\
	done)

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
