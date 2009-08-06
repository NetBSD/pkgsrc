# $NetBSD: Makefile,v 1.1.1.1 2009/08/06 06:23:23 wiz Exp $
#

DISTNAME=	Sigil_code_0.1.1
PKGNAME=	${DISTNAME:S/_code_/-/}
CATEGORIES=	editors
MASTER_SITES=	http://sigil.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sigil/
COMMENT=	Multi-platform WYSIWYG ebook editor (for the ePub format)
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin libexec/Sigil/data

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
EXTRACT_OPTS_ZIP=	-aqo

post-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/Sigil
	${ECHO} '${PREFIX}/libexec/Sigil/Sigil "$$@"' \
		>> ${WRKSRC}/Sigil

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Sigil ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Sigil \
		${DESTDIR}${PREFIX}/libexec/Sigil
	${INSTALL_DATA} ${WRKSRC}/bin/data/* \
		${DESTDIR}${PREFIX}/libexec/Sigil/data

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
