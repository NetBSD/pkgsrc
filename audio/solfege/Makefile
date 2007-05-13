# $NetBSD: Makefile,v 1.12 2007/05/13 13:02:42 schmonz Exp $
#

DISTNAME=		solfege-3.8.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=solfege/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.solfege.org/
COMMENT=		Practice several musical ear training exercises

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_DIRS+=		xdg-1.2
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-pygtk-test
CONFIGURE_ARGS+=	--enable-docbook-stylesheet=${LOCALBASE}/share/xsl/docbook/html/chunk.xsl

USE_TOOLS+=		gmake gm4 makeinfo pkg-config msgfmt

PYTHON_VERSIONS_ACCEPTED=	24 23
PYTHON_PATCH_SCRIPTS=	*.py *.py.in */*.py */*.py.in

SUBST_CLASSES+=		sound
SUBST_STAGE.sound=	do-configure
SUBST_FILES.sound=	default.config
SUBST_SED.sound=	-e 's|@WAVPLAYER@|${WAVPLAYER}|g'
SUBST_SED.sound+=	-e 's|@MIDIPLAYER@|${MIDIPLAYER}|g'
SUBST_MESSAGE.sound=	Setting default audio player.

EGDIR=			${PREFIX}/share/examples/solfege
CONF_FILES+=		${EGDIR}/solfege ${PKG_SYSCONFDIR}/solfege
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
WAVPLAYER=	/usr/bin/audioplay
MIDIPLAYER=	/usr/bin/midiplay
.elif ${OPSYS} == "Darwin"
WAVPLAYER=	${LOCALBASE}/bin/qtplay
MIDIPLAYER=	${LOCALBASE}/bin/qtplay
DEPENDS+=	qtplay-[0-9]*:../../audio/qtplay
.endif

.include "../../lang/python/application.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
