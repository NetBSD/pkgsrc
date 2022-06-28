# $NetBSD: Makefile,v 1.47 2022/06/28 11:33:59 wiz Exp $

DISTNAME=	asymptote-2.79
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asymptote/}
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asymptote.sourceforge.io/
COMMENT=	Powerful descriptive vector graphics language for technical drawings
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

TOOL_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
TOOL_DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
TOOL_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TOOL_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TOOL_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
TOOL_DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
TOOL_DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
TOOL_DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
TOOL_DEPENDS+=	tex-media9-[0-9]*:../../print/tex-media9
TOOL_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
TOOL_DEPENDS+=	tex-parskip-[0-9]*:../../print/tex-parskip
TOOL_DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
TOOL_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
TOOL_DEPENDS+=	ghostscript-agpl>=9.16:../../print/ghostscript-agpl
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry

# Unclear what version is required -- 4.8 is too old, 6.8 is new enough.
# Let's just leave it at 6.8 since that's what's in pkgsrc now.
TEXINFO_REQD=		6.8

UNLIMIT_RESOURCES=	datasize
MAKE_JOBS_SAFE=		no # random failure during build as of 2.38

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES=		c c++11

CONFIGURE_ARGS+=	--enable-gc=system
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
USE_TOOLS+=		gmake makeinfo perl
CFLAGS+=		-DGC_NO_THREAD_REDIRECTS

REPLACE_PYTHON+=	GUI/*.py

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	Makefile.in
SUBST_MESSAGE.python=	Fixing path to python interpreter.
SUBST_SED.python+=	-e "s|/usr/bin/env python3|${PYTHONBIN:Q}|g"

# DragonFly has stripped makeinfo in the base - without texi2dvi.
OPSYSVARS+=			TOOL_DEPENDS
TOOL_DEPENDS.DragonFly+=	gtexinfo-[0-9]*:../../devel/gtexinfo

#
# Ghostscript running in a pipe fails with:
#
# ../asy -dir ../base -config "" -render=0 -f pdf -noprc helix.asy
# GPL Ghostscript 9.53.0:
#   *** EPS files may not contain multiple pages.
#   *** Use of the %d filename format is required to output pages to multiple EPS files.
# GPL Ghostscript 9.53.0: Unrecoverable error, exit code 1
#
# leaving asy hanging indefinitely.
#
NOT_FOR_BULK_PLATFORM+=	SunOS-* NetBSD-*

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
# wants library called 'glut', but pkgsrc only provides 'freeglut'
#BUILDLINK_API_DEPENDS.freeglut+=	freeglut>=3.0
#.include "../../graphics/freeglut/buildlink3.mk"
# recognized, but makes asy dump core during creation of documentation
#.include "../../graphics/glut/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
