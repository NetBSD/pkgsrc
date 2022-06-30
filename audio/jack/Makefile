# $NetBSD: Makefile,v 1.52 2022/06/30 11:18:02 nia Exp $

DISTNAME=	jack2-1.9.19
PKGNAME=	${DISTNAME:S/jack2/jack/1}
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=jackaudio/}
GITHUB_PROJECT=	jack2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://jackaudio.org/
COMMENT=	Low-latency audio server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config bash

WAF_ARGS+=	--systemd=no
WAF_ARGS+=	--readline=no

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	alsa
.if ${OPSYS} == "Linux"
PLIST.alsa=	yes
.endif

PLIST_VARS+=	boomer oss
.if ${OPSYS} == "SunOS"
PLIST.boomer=	yes
PLIST.oss=	yes
# Wants POSIXy getgrnam_r(3)
CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
.endif

PLIST_VARS+=	sun
.if ${OPSYS} == "NetBSD"
PLIST.sun=	yes
.endif

PLIST_VARS+=	darwin
.if ${OPSYS} == "Darwin"
PLIST.darwin=	yes

post-install:
	${RUN} cd ${DESTDIR}${PREFIX} && \
		for f in lib/jack/*.so; do \
			install_name_tool -id ${PREFIX}/$$f $$f; \
		done
.endif

REPLACE_PYTHON+=	waf
REPLACE_PYTHON+=	tools/jack_control
REPLACE_BASH+=		svnversion_regenerate.sh

PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGCONFIG_OVERRIDE+=		jack.pc.in

.include "../../lang/python/application.mk"
.include "../../devel/waf/waf.mk"
.if ${OPSYS} == "Darwin"
.  include "../../audio/aften/buildlink3.mk"
.endif
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
#.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
