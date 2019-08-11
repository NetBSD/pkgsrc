# $NetBSD: Makefile,v 1.46 2019/08/11 13:22:39 wiz Exp $

DISTNAME=	ghostscript-${GS_VERSION}
PKGNAME=	${DISTNAME:S/ghostscript/ghostscript-agpl/}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=ArtifexSoftware/}
GITHUB_PROJECT=	ghostpdl-downloads
GITHUB_RELEASE=	gs${GS_VERSION:S/.//}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ghostscript.com/
COMMENT=	Postscript interpreter

# Upstream calls this "GPL Ghostscript", which is confusing;
# see https://bugs.ghostscript.com/show_bug.cgi?id=700877
# Plus adobe verbatim for Resources/CMap.
LICENSE=	gnu-agpl-v3

.include	"Makefile.common"

DEPENDS+=		ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake perl:run lex pkg-config
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES+=	datasize	# gsromfs1.c

BUILD_TARGET=		so
INSTALL_TARGET=		soinstall

CONFIGURE_ARGS+=	--enable-openjpeg
CONFIGURE_ARGS+=	--with-system-libtiff
CONFIGURE_ENV+=		LPLIBDIR=${PREFIX}/lib
CONFIGURE_ENV.HPUX+=	ac_cv_func_fopen64=no

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

# \todo Remove "a4" as that is not valid according to pkglint.
.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
BUILD_DEFS+=		PAPERSIZE
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

# Not ideal but too many files hardcode _XOPEN_SOURCE=500.
.if !empty(CC_VERSION:Mgcc-[6-9]*) || !empty(PKGSRC_COMPILER:Mclang)
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
.else
CPPFLAGS.SunOS+=	-D__C99FEATURES__
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
	${RM} -rf ${WRKSRC}/openjpeg
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
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.10.0
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
