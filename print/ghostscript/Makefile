# $NetBSD: Makefile,v 1.67 2009/09/02 15:57:08 wiz Exp $

DISTNAME=	ghostscript-8.70
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ghostscript/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ghostscript.sourceforge.net/
COMMENT=	Postscript interpreter

DEPENDS+=		ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

CONFLICTS+=		ghostscript-afpl-[0-9]*
CONFLICTS+=		ghostscript-esp{,-nox11}-[0-9]*
CONFLICTS+=		ghostscript-gnu{,-nox11,-x11}-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl:run lex pkg-config
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
UNLIMIT_RESOURCES+=	datasize	# gsromfs1.c

BUILD_TARGET=		so
INSTALL_TARGET=		soinstall
CONFIGURE_ARGS+=	-with-omni=no	# otherwise pulls in libstdc++

REPLACE_PERL+=		lib/fixmswrd.pl

GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/${PKGVERSION}/Resource

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
CFLAGS+=		-DA4
.endif

REQD_DIRS+=		share/ghostscript

SUBST_CLASSES+=		resdir
SUBST_STAGE.resdir=	post-extract
SUBST_MESSAGE.resdir=	Fixing resource directory path
SUBST_FILES.resdir=	Resource/Init/gs_res.ps
SUBST_SED.resdir=	-e "s|/Resource/|${GS_RESOURCEDIR}/|g"

.if ${OPSYS} == "HPUX"
CONFIGURE_ENV+=		ac_cv_func_fopen64=no
.endif

# On Linux-*-x86_64, there was an error message:
# gp_unix.o: relocation R_X86_64_32 against `a local symbol' can not be
# used when making a shared object; recompile with -fPIC
CFLAGS.NetBSD=		-fPIC
CFLAGS.Linux=		-fPIC
CFLAGS.SunOS=		-fPIC

# Interim IRIX build fix, the real problem is that fontconfig.pc doesn't
# require linking against libiconv when it should do so.
.if ${OPSYS} == "IRIX"
BUILDLINK_TRANSFORM+=	l:fontconfig:fontconfig:iconv
.endif

CONFIGURE_ENV+=	LPLIBDIR=${LOCALBASE}/lib

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj
#	${MV} ${WRKSRC}/jasper ${WRKSRC}/jasper.dontuse
	${MV} ${WRKSRC}/libpng ${WRKSRC}/libpng.dontuse
#	${MV} ${WRKSRC}/zlib ${WRKSRC}/zlib.dontuse

post-install:
	${LN} -sf gsc ${DESTDIR}${PREFIX}/bin/gs

.include "options.mk"

.include "../../print/libpaper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# pkgsrc jasper is too new
#.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
