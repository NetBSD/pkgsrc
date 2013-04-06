# $NetBSD: Makefile,v 1.7 2013/04/06 19:42:42 rodent Exp $
#

DISTNAME=	libvdpau-0.5
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://http.download.nvidia.com/XFree86/vdpau/doxygen/html/index.html
COMMENT=	Video Decode and Presentation API for Unix
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
CONFIGURE_ARGS+=	--disable-documentation

AUTO_MKDIRS=	yes

PKGCONFIG_OVERRIDE+=	vdpau.pc.in

DOCDIR=		${PREFIX}/share/doc/libvdpau
EGDIR=		${PREFIX}/share/examples/libvdpau
CONF_FILES=	${EGDIR}/vdpau_wrapper.cfg \
		${PKG_SYSCONFDIR}/vdpau_wrapper.cfg

INSTALL_MAKE_FLAGS=	sysconfdir=${EGDIR}

DOCFILES=		README NEWS COPYING AUTHORS
post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} ${DOCFILES} ${DESTDIR}${DOCDIR}

.include "available.mk"
.if ${VDPAU_AVAILABLE} == no
PKG_FAIL_REASON=	"VDPAU is not available on this platform"
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
