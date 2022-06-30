# $NetBSD: Makefile,v 1.26 2022/06/30 11:18:03 nia Exp $

DISTNAME=	speech-dispatcher-0.10.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=brailcom/}
GITHUB_PROJECT=	speechd
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://devel.freebsoft.org/speechd
COMMENT=	Common interface to speech synthesis library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config makeinfo
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++

INFO_FILES=	yes

PY_PATCHPLIST=	yes

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man
TOOL_DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

# To avoid PLIST complexity, let the libao package select the most
# fitting audio backend for the platform.
CONFIGURE_ARGS+=	--with-libao
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--without-nas
CONFIGURE_ARGS+=	--without-oss
CONFIGURE_ARGS+=	--without-pulse

.include "../../mk/bsd.prefs.mk"

PKGCONFIG_OVERRIDE+=	speech-dispatcher.pc.in

PKG_SYSCONFSUBDIR=	speech-dispatcher

OWN_DIRS+=	${PKG_SYSCONFDIR}/clients
OWN_DIRS+=	${PKG_SYSCONFDIR}/modules

CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/clients/emacs.conf \
		${PKG_SYSCONFDIR}/clients/emacs.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/speechd.conf \
		${PKG_SYSCONFDIR}/speechd.conf

PLIST_VARS+=	espeak

MODULES=	baratinoo.conf cicero.conf dtk-generic.conf epos-generic.conf \
		festival.conf flite.conf ibmtts.conf ivona.conf kali.conf \
		llia_phon-generic.conf mary-generic-disabled.conf \
		swift-generic.conf voxin.conf
.if ${OPSYS} != "Darwin"
# espeak officially says it does not support macOS:
# https://github.com/rhdunn/espeak/issues/78
MODULES+=	espeak-mbrola-generic.conf espeak-ng-mbrola-generic.conf \
		espeak-ng.conf espeak.conf
PLIST.espeak=	yes
.endif

.for module in ${MODULES}
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/${module} \
		${PKG_SYSCONFDIR}/modules/${module}
.endfor

REPLACE_PYTHON+=	src/api/python/speechd_config/spd-conf

# temporary fix for GLib 2.68 breakage
# # https://gitlab.gnome.org/GNOME/glib/-/merge_requests/1963
CXXFLAGS+=              -DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_66
BUILDLINK_API_DEPENDS.glib2	+=	glib2>=2.66.0

.if ${OPSYS} != "Darwin"
.include "../../audio/espeak/buildlink3.mk"
.endif
.include "../../audio/flite/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/dotconf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
