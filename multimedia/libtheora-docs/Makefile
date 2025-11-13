# $NetBSD: Makefile,v 1.20 2025/11/13 06:50:43 wiz Exp $

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
PKGREVISION=	2
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

TOOL_DEPENDS+=	doxygen>=1.15.0:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
