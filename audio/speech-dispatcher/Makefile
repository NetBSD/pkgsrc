# $NetBSD: Makefile,v 1.5 2017/09/08 02:38:37 ryoon Exp $

DISTNAME=	speech-dispatcher-0.8.4
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://devel.freebsoft.org/pub/projects/speechd/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://devel.freebsoft.org/speechd
COMMENT=	Common interface to speech synthesis library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config

PKGCONFIG_OVERRIDE+=	speech-dispatcher.pc.in

CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/clients/emacs.conf \
		${PKG_SYSCONFDIR}/clients/emacs.conf
CONF_FILES+=	${PREFIX}/share/examples/speech-dispatcher/modules/cicero.conf \
		${PKG_SYSCONFDIR}/modules/cicero.conf
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

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/dotconf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
