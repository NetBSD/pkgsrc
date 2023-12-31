# $NetBSD: Makefile,v 1.17 2023/12/31 09:49:19 wiz Exp $

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
PKGREVISION=	9
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

TOOL_DEPENDS+=	doxygen>=1.10.0:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
