# $NetBSD: Makefile,v 1.29 2007/07/01 20:56:27 markd Exp $

DISTNAME=	ghostscript-8.54-gpl
PKGNAME=	ghostscript-8.54
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ghostscript/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ghostscript.sourceforge.net/
COMMENT=	Postscript interpreter

CONFLICTS+=		ghostscript-afpl-[0-9]*
CONFLICTS+=		ghostscript-esp{,-nox11}-[0-9]*
CONFLICTS+=		ghostscript-gnu{,-nox11,-x11}-[0-9]*

DEPENDS+=		ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
CFLAGS+=		-DA4
.endif

REQD_DIRS+=		share/ghostscript

SUBST_CLASSES+=		resdir
SUBST_STAGE.resdir=	post-extract
SUBST_MESSAGE.resdir=	Fixing resource directory path
SUBST_FILES.resdir=	lib/gs_res.ps
SUBST_SED.resdir=	-e "s|/Resource/|${GS_RESOURCEDIR}/|g"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj
	${MV} ${WRKSRC}/jasper ${WRKSRC}/jasper.dontuse
	${MV} ${WRKSRC}/libpng ${WRKSRC}/libpng.dontuse
	${MV} ${WRKSRC}/zlib ${WRKSRC}/zlib.dontuse

.include "options.mk"

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
