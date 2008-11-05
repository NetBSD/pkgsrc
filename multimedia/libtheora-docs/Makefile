# $NetBSD: Makefile,v 1.1.1.1 2008/11/05 14:24:05 wiz Exp $
#

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
