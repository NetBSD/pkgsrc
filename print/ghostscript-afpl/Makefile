# $NetBSD: Makefile,v 1.2.2.1 2005/12/11 12:04:26 seb Exp $
#

DISTNAME=		ghostscript-8.51
PKGNAME=		ghostscript-afpl-8.51
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ghostscript/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ghostscript.sourceforge.net/
COMMENT=		Postscript interpreter

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

GS_SRCS=                ${DISTNAME}${EXTRACT_SUFX}
DISTFILES=             ${GS_SRCS}
EXTRACT_ONLY=           ${GS_SRCS}

# Adobe's JPEG implementation in their PDF/PS documents is non-standard,
# so we can't use an already installed libjpeg.so.
#
JPEG_SRCS=              jpegsrc.v6b.tar.gz
JPEG_WRKSRC=            ${WRKDIR}/jpeg-6b
SITES_${JPEG_SRCS}=     ftp://ftp.uu.net/graphics/jpeg/
DISTFILES+=             ${JPEG_SRCS}
EXTRACT_ONLY+=          ${JPEG_SRCS}

GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj
	${LN} -fs ${JPEG_WRKSRC} ${WRKSRC}/jpeg
	${MV} ${WRKSRC}/jasper ${WRKSRC}/jasper.dontuse
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
