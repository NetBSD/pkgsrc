# $NetBSD: Makefile,v 1.31 2026/09/02 19:00:53 wiz Exp $

DISTNAME=	kew-4.3.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=ravachol/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	kew

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/ravachol/kew/
COMMENT=	Terminal music player with album art
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

# for "error: initializer element is not constant"
GCC_REQD+=	8

USE_TOOLS+=	pkg-config gmake

MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/512x512/apps
INSTALLATION_DIRS+=	share/kew

.include "options.mk"

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../graphics/chafa/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
