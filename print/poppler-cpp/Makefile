# $NetBSD: Makefile,v 1.11 2013/10/29 19:05:23 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-cpp-${POPPLER_VERS}

COMMENT=		PDF rendering library (cpp wrapper)
MAINTAINER=		reed@reedmedia.net

CONFLICTS+=		poppler<0.4.5nb1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-glib.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# Don't build the cairo graphics backend, required by glib.
CONFIGURE_ARGS+=	--disable-cairo-output
# Don't build the splash graphics backend.
CONFIGURE_ARGS+=	--disable-splash-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils

BUILDLINK_API_DEPENDS.poppler+=	poppler-${POPPLER_VERS}{,nb*}
.include "../../print/poppler/buildlink3.mk"

BUILD_DIRS=		cpp
INSTALL_DIRS=		cpp

INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../converters/libiconv/buildlink3.mk"

CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=	--with-libiconv-prefix
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-cpp.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
