# $NetBSD: Makefile,v 1.1.1.1 2009/04/14 18:33:30 wiz Exp $
#

DISTNAME=	OdfConverter--src-1.1
PKGNAME=	OdfConverter-1.1
CATEGORIES=	converters textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=odf-converter/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odf-converter.sourceforge.net/
COMMENT=	Converter between Microsoft Office 2007 and OpenOffice formats

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config

BUILD_DIRS=	source/Common/OdfZipUtils
BUILD_DIRS+=	source/Common/OdfConverterLib
BUILD_DIRS+=	source/Word/Converter
BUILD_DIRS+=	source/Presentation/Converter
BUILD_DIRS+=	source/Spreadsheet/Converter
BUILD_DIRS+=	source/AdditionalTools/zlib123/contrib/minizip
BUILD_DIRS+=	source/Shell/OdfConverterTest

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin share/doc/OdfConverter

post-extract:
	cd ${WRKDIR} && mv "Copy of 4thMarch" ${DISTNAME:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/Shell/OdfConverterTest/OdfConverter \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/source/Shell/OdfConverterTest/README.TXT \
		${DESTDIR}${PREFIX}/share/doc/OdfConverter

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
