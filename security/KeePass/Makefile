# $NetBSD: Makefile,v 1.12 2014/05/05 00:48:18 ryoon Exp $
#

DISTNAME=	KeePass-2.23
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=keepass/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keepass.info/
COMMENT=	Free, open source, light-weight and easy-to-use password manager
LICENSE=	gnu-gpl-v2

DEPENDS+=	mono>=2.6<3:../../lang/mono2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin libexec/KeePass/XSL

do-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/KeePass
	${ECHO} "${PREFIX}/bin/mono ${PREFIX}/libexec/KeePass/KeePass.exe "'"$$@"' >> ${WRKSRC}/KeePass

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/KeePass ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.* ${DESTDIR}${PREFIX}/libexec/KeePass
	${INSTALL_DATA} ${WRKSRC}/XSL/* ${DESTDIR}${PREFIX}/libexec/KeePass/XSL

.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
