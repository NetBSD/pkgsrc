# $NetBSD: Makefile,v 1.1 2015/12/27 23:35:33 kamil Exp $

# During upgrade please adjust files/wscript and doublecheck libs major/minor
DISTNAME=	vamp-plugin-sdk-2.6
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/1520/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vamp-plugins.org/
COMMENT=	The Vamp audio analysis plugin system
LICENSE=	x11

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-hostsdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-sdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp.pc.in

BUILD_DEPENDS+=	waf-[0-9]*:../../devel/waf

pre-patch:
	${RUN} cp ${FILESDIR}/wscript ${WRKSRC}

.include "../../devel/waf/waf.mk"
# Missing --mandir
WAF_ARGS=
.include "../../math/fftw/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
