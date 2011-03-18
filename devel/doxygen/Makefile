# $NetBSD: Makefile,v 1.82 2011/03/18 23:51:16 minskim Exp $

DISTNAME=	doxygen-1.6.3.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.doxygen.org/
COMMENT=	Documentation system for C++, Java, IDL and C
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
BUILD_DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	tex-a4wide>=2010nb1:../../print/tex-a4wide
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss
DEPENDS+=	tex-pspicture-[0-9]*:../../print/tex-pspicture
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	texlive-pdftools-[0-9]*:../../print/texlive-pdftools

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
UNLIMIT_RESOURCES+=	datasize
USE_TOOLS+=		gmake gs:run perl:run bison flex
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--make ${GMAKE}
CONFIGURE_ARGS+=	--perl ${PERL5}
CONFIGURE_ARGS+=	--install ${INSTALL}
CONFIGURE_ARGS+=	--dot ${PREFIX}/bin/dot
CONFIGURE_ARGS+=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--docdir ${PREFIX}/share/doc/doxygen
MAKE_ENV+=		PKGSRC_CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		MAN1DIR=${PKGMANDIR}/man1

PLIST_VARS+=		ci cs

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	doc/Makefile.in
SUBST_SED.path=		-e "s|@EPSTOPDF@|${LOCALBASE}/bin/epstopdf|g" \
			-e "s|@PYTHONBIN@|${PYTHONBIN}|g"

SUBST_CLASSES+=		perlbin
SUBST_STAGE.perlbin=	pre-configure
SUBST_MESSAGE.perlbin=	Fixing hardcoded path to the Perl interpreter
SUBST_FILES.perlbin=	examples/tag.cfg
SUBST_SED.perlbin=	-e 's,^PERL_PATH.*,PERL_PATH = ${PERL5},'

SUBST_CLASSES+=		epstopdf
SUBST_STAGE.epstopdf=	pre-configure
SUBST_MESSAGE.epstopdf=	Fixing path to epstopdf
SUBST_FILES.epstopdf=	src/diagram.cpp src/docparser.cpp src/dot.cpp \
			src/msc.cpp
SUBST_SED.epstopdf=	-e 's,"epstopdf","${LOCALBASE}/bin/epstopdf",g'

PRIVILEGED_STAGES+=	clean

INSTALL_TARGET=		install install_docs

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.ci=		yes	# case-insensitive
.else
PLIST.cs=		yes	# case-sensitive
.endif

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	-platform freebsd-g++
.endif

post-patch:
	touch ${WRKSRC}/src/doxytag.l

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.12nb1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
