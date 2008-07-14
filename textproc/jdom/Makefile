# $NetBSD: Makefile,v 1.5 2008/07/14 12:56:13 joerg Exp $
#

DISTNAME=	jdom-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.jdom.org/dist/binary/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jdom.org/
COMMENT=	Simple API for processing XML documents in Java

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

USE_LANGUAGES=	# only Java
USE_TOOLS+=	pax
AUTO_MKDIRS=			yes

do-build:
	cd ${WRKSRC}/src/java && ${LOCALBASE}/bin/zip -r ${WRKSRC}/jdom-src.zip org

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} build/jdom.jar jdom-src.zip ${DESTDIR}${PREFIX}/lib/java/
	cd ${WRKSRC}/build/apidocs && pax -wr * ${DESTDIR}${PREFIX}/share/doc/jdom/

.include "../../mk/bsd.pkg.mk"
