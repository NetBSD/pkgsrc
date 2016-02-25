# $NetBSD: Makefile,v 1.21 2016/02/25 13:37:47 jperkin Exp $
#

DISTNAME=	asymptote-2.15
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asymptote/}
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://asymptote.sourceforge.net/
COMMENT=	Powerful descriptive vector graphics language for technical drawings
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
BUILD_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
BUILD_DEPENDS+=	tex-parskip-[0-9]*:../../print/tex-parskip
BUILD_DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
BUILD_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
USE_TOOLS+=	gs

UNLIMIT_RESOURCES=	datasize

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES=          c c++

CONFIGURE_ARGS+=	--enable-gc=system
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
USE_TOOLS+=		gmake makeinfo perl
CFLAGS+=		-DGC_NO_THREAD_REDIRECTS

REPLACE_PYTHON+=	GUI/*.py

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	Makefile.in
SUBST_MESSAGE.python=	Fixing path to python interpreter.
SUBST_SED.python+=	-e "s|/usr/bin/env python|${PYTHONBIN:Q}|g"

# DragonFly has stripped makeinfo in the base - without texi2dvi.
OPSYSVARS+=			BUILD_DEPENDS
BUILD_DEPENDS.DragonFly+=	gtexinfo-[0-9]*:../../devel/gtexinfo

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xasy.1x \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xasy.1

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
# next two could be split off into options
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
# freeglut too old, not recognized
#.include "../../graphics/freeglut/buildlink3.mk"
# recognized, but makes asy dump core during creation of documentation
#.include "../../graphics/glut/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
