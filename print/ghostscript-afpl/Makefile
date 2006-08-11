# $NetBSD: Makefile,v 1.14 2006/08/11 13:59:52 gdt Exp $

DISTNAME=	ghostscript-8.54
PKGNAME=	ghostscript-afpl-8.54
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ghostscript/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ghostscript.sourceforge.net/
COMMENT=	Postscript interpreter

LICENSE=	afpl-license
RESTRICTED=	Commercial distribution prohibited in most cases.
# CDROM distribution may be acceptable in some cases, but not all, so
# the variables are set.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}


CONFLICTS+=		ghostscript{,-nox11}-[0-9]*
CONFLICTS+=		ghostscript-esp{,-nox11}-[0-9]*
CONFLICTS+=		ghostscript-gnu{,-nox11,-x11}-[0-9]*

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource

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

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
