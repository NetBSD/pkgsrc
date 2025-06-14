# $NetBSD: Makefile,v 1.19 2025/06/14 05:47:36 wiz Exp $

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
PKGREVISION=	1
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

TOOL_DEPENDS+=	doxygen>=1.14.0:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
