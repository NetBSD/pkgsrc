# $NetBSD: Makefile,v 1.11 2006/05/22 17:20:39 drochner Exp $

DISTNAME=	ghostscript-8.54
PKGNAME=	ghostscript-afpl-8.54
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ghostscript/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ghostscript.sourceforge.net/
COMMENT=	Postscript interpreter

CONFLICTS+=		ghostscript{,-nox11}-[0-9]*
CONFLICTS+=		ghostscript-esp{,-nox11}-[0-9]*
CONFLICTS+=		ghostscript-gnu{,-nox11,-x11}-[0-9]*

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

GS_SRCS=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES=		${GS_SRCS}
EXTRACT_ONLY=		${GS_SRCS}

GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj
	${MV} ${WRKSRC}/jasper ${WRKSRC}/jasper.dontuse
	${MV} ${WRKSRC}/libpng ${WRKSRC}/libpng.dontuse
	${MV} ${WRKSRC}/zlib ${WRKSRC}/zlib.dontuse
	cd ${WRKSRC}/lib; for file in gs_res.ps; do			\
		${SED}  -e "s|/Resource/|${GS_RESOURCEDIR}/|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
