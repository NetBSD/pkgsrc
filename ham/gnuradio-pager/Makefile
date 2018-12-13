# $NetBSD: Makefile,v 1.13 2018/12/13 19:52:03 adam Exp $

PKGNAME=	gnuradio-pager-${VERSION}
PKGREVISION=	2
COMMENT=	FLEX radiopager receiver/demodulator of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_PAGER=ON

.include	"../../mk/bsd.pkg.mk"

# --   Dependency Boost_FOUND = 1
# --   Dependency ENABLE_GNURADIO_RUNTIME = ON
# --   Dependency ENABLE_GR_FILTER = ON
# --   Dependency ENABLE_GR_ANALOG = ON
# --   Enabling gr-pager support.
# --   Override with -DENABLE_GR_PAGER=ON/OFF
