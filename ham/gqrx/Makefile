# $NetBSD: Makefile,v 1.4 2025/03/01 17:22:13 adam Exp $

DISTNAME=	gqrx-2.17.6
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=gqrx-sdr/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gqrx-sdr/gqrx
COMMENT=	Open source software defined radio receiver
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
.include "../../audio/portaudio/buildlink3.mk"
.endif
.include "../../devel/cmake/build.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../ham/gnuradio-network/buildlink3.mk"
.include "../../ham/gr-osmosdr/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
