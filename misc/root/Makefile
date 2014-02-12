# $NetBSD: Makefile,v 1.53 2014/02/12 23:18:15 tron Exp $

DISTNAME=		root_v5.26.00b.source
PKGNAME=		root-5.26
PKGREVISION=		13
CATEGORIES=		misc
MASTER_SITES=		ftp://root.cern.ch/root/

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://root.cern.ch/
COMMENT=		OO framework for data analysis and visualisation

WRKSRC=			${WRKDIR}/root
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++ #fortran f2c lacks LOC()
.include "../../lang/gcc3-f77/buildlink3.mk"

CHECK_PORTABILITY_SKIP=	build/win/*.sh cint/tool/INSTALLBIN
BUILD_TARGET=

.if (${MACHINE_ARCH} == "arm")
BROKEN=	Compilation stops due to internal compiler error
.endif

INSTALLATION_DIRS=	bin

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	${LOWER_OPSYS}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}
CONFIGURE_ARGS+=	--enable-soversion
CONFIGURE_ARGS+=	--disable-builtin-pcre
CONFIGURE_ARGS+=	--disable-builtin-freetype
# clarens needs xmlrpc-c, the pkgsrc version is incompatible
CONFIGURE_ARGS+=	--disable-clarens

CONFIGURE_ARGS+=	--with-x11-libdir=${BUILDLINK_PREFIX.libX11}/lib
CONFIGURE_ARGS+=	--with-xpm-libdir=${BUILDLINK_PREFIX.libXpm}/lib

# option, requires libxml2
CONFIGURE_ARGS+=	--disable-xml
#.include "../../textproc/libxml2/buildlink3.mk"

# might be optional
#CONFIGURE_ARGS+=	--disable-asimage
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../math/gsl/buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/Makefile.netbsd ${WRKSRC}/config

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
