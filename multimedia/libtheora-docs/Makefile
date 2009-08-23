# $NetBSD: Makefile,v 1.4 2009/08/23 13:13:33 hasso Exp $
#

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
PKGREVISION=	2
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

BUILD_DEPENDS+=	doxygen>=1.5.9:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
