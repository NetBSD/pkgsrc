# $NetBSD: Makefile,v 1.3 2009/02/16 00:02:57 wiz Exp $
#

.include "../../multimedia/libtheora/Makefile.common"

PKGNAME=	${DISTNAME:S/theora/theora-docs/}
PKGREVISION=	1
COMMENT=	Video codec for Ogg multimedia streaming (API documentation)

BUILD_DEPENDS+=	doxygen>=1.5.7.1:../../devel/doxygen

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	ac_cv_func_oggpackB_read=yes

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
