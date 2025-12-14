# $NetBSD: Makefile,v 1.1 2025/12/14 19:57:11 vins Exp $

DISTNAME=	alsa-sndio-0.2
PKGNAME=	${DISTNAME:S/sndio/plugins-sndio/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Duncaen/}
GITHUB_PROJECT=	alsa-sndio
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Duncaen/alsa-sndio/
COMMENT=	ALSA PCM sndio plugin
LICENSE=	isc

USE_TOOLS+=	gmake pkg-config

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_LIB} ${WRKSRC}/libasound_module_pcm_sndio.so	\
		${DESTDIR}/${PREFIX}/lib/alsa-lib
	${INSTALL_DATA} ${WRKSRC}/README.md			\
		${DESTDIR}/${PREFIX}/share/doc/${PKGBASE}/README

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/sndio/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
