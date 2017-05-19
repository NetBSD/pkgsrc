# $NetBSD: Makefile,v 1.25 2017/05/19 13:29:04 prlw1 Exp $

DISTNAME=	ghostscript-${GS_VERSION}
PKGNAME=	${DISTNAME:S/ghostscript/ghostscript-agpl/}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=ArtifexSoftware/ghostpdl-downloads/releases/download/gs921/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ghostscript.com/
COMMENT=	Postscript interpreter
# Plus adobe verbatim for Resources/CMap.
LICENSE=	gnu-agpl-v3

DEPENDS+=		ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

.include "Makefile.common"

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl:run lex pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-system-libtiff
CONFIGURE_ARGS+=	--disable-cups
CONFIGURE_ENV+=		LPLIBDIR=${PREFIX}/lib
CONFIGURE_ENV.HPUX+=	ac_cv_func_fopen64=no
UNLIMIT_RESOURCES+=	datasize	# gsromfs1.c

BUILD_TARGET=		so
INSTALL_TARGET=		soinstall

REPLACE_PERL+=		toolbin/localcluster/clusterpush.pl
REPLACE_PERL+=		toolbin/checkdeps.pl
REPLACE_PERL+=		toolbin/pscet_status.pl
REPLACE_PERL+=		toolbin/performance.pl
REPLACE_PERL+=		toolbin/squeeze2html.pl
REPLACE_PERL+=		toolbin/bugsByEngineer.pl
REPLACE_PERL+=		toolbin/htmldiff.pl

GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/${PKGVERSION}/Resource
# MESSAGE file substitution
MESSAGE_SUBST+=		GS_RESOURCEDIR=${GS_RESOURCEDIR}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
CFLAGS+=		-DA4
.endif

REQD_DIRS+=		share/ghostscript

SUBST_CLASSES+=		resdir
SUBST_STAGE.resdir=	post-extract
SUBST_MESSAGE.resdir=	Fixing resource directory path
SUBST_FILES.resdir=	Resource/Init/gs_res.ps
SUBST_SED.resdir=	-e "s|/Resource/|${GS_RESOURCEDIR}/|g"

# On Linux-*-x86_64, there was an error message:
# gp_unix.o: relocation R_X86_64_32 against `a local symbol' can not be
# used when making a shared object; recompile with -fPIC
.if !empty(PKGSRC_COMPILER:Mgcc) || !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-fPIC
.endif

# Interim IRIX build fix, the real problem is that fontconfig.pc doesn't
# require linking against libiconv when it should do so.
BUILDLINK_TRANSFORM.IRIX+=	l:fontconfig:fontconfig:iconv

.include "options.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj
	${RM} -rf ${WRKSRC}/freetype
	${RM} -rf ${WRKSRC}/jbig2dec
	${RM} -rf ${WRKSRC}/jpeg
	${RM} -rf ${WRKSRC}/lcms2
	${RM} -rf ${WRKSRC}/libpng
	${RM} -rf ${WRKSRC}/tiff
	${RM} -rf ${WRKSRC}/zlib

#  To allow outside customization, rename cidfmap
#	 (if you look at inside of the file, it is logically empty)
.if !empty(PKG_OPTIONS:Mdisable-compile-inits)
	(cd ${WRKSRC}/Resource/Init/; ${MV} cidfmap cidfmap.dist)
.endif

post-install:
	${LN} -sf gsc ${DESTDIR}${PREFIX}/bin/gs

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
#.include "../../graphics/openjpeg15/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
