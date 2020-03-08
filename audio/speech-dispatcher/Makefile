# $NetBSD: Makefile,v 1.14 2020/03/08 16:47:26 wiz Exp $

DISTNAME=	speech-dispatcher-0.9.1
PKGREVISION=	2
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
USE_TOOLS+=	gmake intltool pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++03

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

# msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

PKGCONFIG_OVERRIDE+=	speech-dispatcher.pc.in

PKG_SYSCONFSUBDIR=	speech-dispatcher

OWN_DIRS+=	${PKG_SYSCONFDIR}/clients
OWN_DIRS+=	${PKG_SYSCONFDIR}/modules

CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/clients/emacs.conf \
		${PKG_SYSCONFDIR}/clients/emacs.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/cicero.conf \
		${PKG_SYSCONFDIR}/modules/cicero.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/speechd.conf \
		${PKG_SYSCONFDIR}/speechd.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/dtk-generic.conf \
		${PKG_SYSCONFDIR}/modules/dtk-generic.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/epos-generic.conf \
		${PKG_SYSCONFDIR}/modules/epos-generic.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/espeak-generic.conf \
		${PKG_SYSCONFDIR}/modules/espeak-generic.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/espeak-mbrola-generic.conf \
		${PKG_SYSCONFDIR}/modules/espeak-mbrola-generic.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/espeak.conf \
		${PKG_SYSCONFDIR}/modules/espeak.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/festival.conf \
		${PKG_SYSCONFDIR}/modules/festival.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/flite.conf \
		${PKG_SYSCONFDIR}/modules/flite.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/ibmtts.conf \
		${PKG_SYSCONFDIR}/modules/ibmtts.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/ivona.conf \
		${PKG_SYSCONFDIR}/modules/ivona.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/llia_phon-generic.conf \
		${PKG_SYSCONFDIR}/modules/llia_phon-generic.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/pico-generic.conf \
		${PKG_SYSCONFDIR}/modules/pico-generic.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/swift-generic.conf \
		${PKG_SYSCONFDIR}/modules/swift-generic.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/speechd.conf \
		${PKG_SYSCONFDIR}/speechd.conf

REPLACE_PYTHON+=	src/api/python/speechd_config/spd-conf

.include "../../audio/espeak/buildlink3.mk"
.include "../../audio/flite/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/dotconf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
