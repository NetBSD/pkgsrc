# $NetBSD: Makefile,v 1.2 2024/10/24 15:25:27 ktnb Exp $

DISTNAME=	kew-3.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=ravachol/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/ravachol/kew/
COMMENT=	Terminal music player with album art
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config gmake

MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

.include "options.mk"

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../graphics/chafa/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
