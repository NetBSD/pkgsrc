# $NetBSD: Makefile,v 1.37 2004/10/03 00:14:56 tv Exp $

DISTNAME=		plplot-5.2.1
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=plplot/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://plplot.sourceforge.net/
COMMENT=		Scientific plotting package

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_GNU_TOOLS+=		m4 make
USE_FORTRAN=		# defined
USE_X11=		# defined
USE_PERL5=		build
USE_LIBTOOL=		# defined

CONFIGURE_ENV+=		GDINCDIR=${BUILDLINK_PREFIX.gd}/include
CONFIGURE_ENV+=		GDLIBDIR=${BUILDLINK_PREFIX.gd}/lib
CONFIGURE_ENV+=		PNGINCDIR=${BUILDLINK_PREFIX.png}/include
CONFIGURE_ENV+=		PNGLIBDIR=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ENV+=		JPEGINCDIR=${BUILDLINK_PREFIX.jpeg}/include
CONFIGURE_ENV+=		JPEGLIBDIR=${BUILDLINK_PREFIX.jpeg}/lib
CONFIGURE_ENV+=		ZLIBINCDIR=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ENV+=		ZLIBLIBDIR=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ENV+=		TCLINCDIR=${BUILDLINK_PREFIX.tcl}/include
CONFIGURE_ENV+=		TCLPRIVATEINCDIR=${BUILDLINK_PREFIX.tcl}/include/tcl/generic
CONFIGURE_ENV+=		TCLLIBDIR=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ENV+=		TKINCDIR=${BUILDLINK_PREFIX.tk}/include
CONFIGURE_ENV+=		TKPRIVATEINCDIR=${BUILDLINK_PREFIX.tk}/include/tk/generic
CONFIGURE_ENV+=		TKLIBDIR=${BUILDLINK_PREFIX.tk}/lib

CONFIGURE_ARGS+=	--enable-drivers
CONFIGURE_ARGS+=	--enable-dyndrivers
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-f77
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--enable-tcl
CONFIGURE_ARGS+=	--disable-itcl
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-octave
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-itcl
CONFIGURE_ARGS+=	--disable-dp
CONFIGURE_ARGS+=	--without-freetype
CONFIGURE_ARGS+=	--without-pthreads
CONFIGURE_ARGS+=	--without-qhull
CONFIGURE_ARGS+=	--without-csa

post-patch:
	${MV} -f ${WRKSRC}/src/plctrl.c ${WRKSRC}/src/plctrl.c.dist
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' ${WRKSRC}/src/plctrl.c.dist \
		> ${WRKSRC}/src/plctrl.c

post-install:
	cd ${PREFIX}/bin && ${LN} -fs libtool plplot_libtool

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../lang/tcl83/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
