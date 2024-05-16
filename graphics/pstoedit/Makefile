# $NetBSD: Makefile,v 1.132 2024/05/16 06:15:03 wiz Exp $

DISTNAME=	pstoedit-3.78
PKGREVISION=	17
CATEGORIES=	converters graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstoedit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pstoedit.net/
COMMENT=	Convert PostScript / PDF into various vector graphic formats
LICENSE=	gnu-gpl-v2
# man page indicates that there are many licenses and one has to read all
# the source files

USE_TOOLS+=	gs:run pkg-config

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
# needs libEMF which has build problems on alpha and probably
# other 64-bit systems
CONFIGURE_ARGS+=	--without-emf
CONFIGURE_ENV+=		CXXFLAGS="${CFLAGS} -Dunix"
CONFIGURE_ENV+=		ac_cv_path_GS=${TOOLS_PATH.gs}

GNU_CONFIGURE_LIBSUBDIR=	pstoedit	# plugin dir -- unused for now
#BUILD_TARGET=

LIBS.SunOS+=	-ldl

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

SUBST_CLASSES+=		magick
SUBST_STAGE.magick=	pre-configure
SUBST_FILES.magick=	configure
SUBST_SED.magick+=	-e 's|ImageMagick|Magick|g'

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	for f in ${WRKSRC}/doc/*.htm; do \
		${INSTALL_DATA} $${f} ${DESTDIR}${DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/readme.txt ${DESTDIR}${DOCDIR}

.include "../../archivers/libzip/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
