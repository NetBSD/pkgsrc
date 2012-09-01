# $NetBSD: Makefile,v 1.6 2012/09/01 19:28:26 marino Exp $
#

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
PKGREVISION=	1
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

BUILD_DEPENDS+=	doxygen>=1.8.2:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
