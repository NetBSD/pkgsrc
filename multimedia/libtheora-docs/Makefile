# $NetBSD: Makefile,v 1.5 2009/10/20 15:48:02 wiz Exp $
#

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

BUILD_DEPENDS+=	doxygen>=1.5.9:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
