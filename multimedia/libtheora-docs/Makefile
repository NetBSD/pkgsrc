# $NetBSD: Makefile,v 1.16 2023/12/25 17:13:10 wiz Exp $

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
PKGREVISION=	8
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

TOOL_DEPENDS+=	doxygen>=1.9.7:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
