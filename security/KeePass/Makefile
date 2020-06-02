# $NetBSD: Makefile,v 1.22 2020/06/02 08:24:39 adam Exp $

DISTNAME=	KeePass-2.44
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=keepass/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keepass.info/
COMMENT=	Free, open source, light-weight and easy-to-use password manager
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/keepass
EXTRACT_DIR=	${WRKDIR}/keepass
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin libexec/KeePass/XSL
INSTALLATION_DIRS+=	share/applications

do-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/KeePass
	${ECHO} "${PREFIX}/bin/mono ${PREFIX}/libexec/KeePass/KeePass.exe "'"$$@"' >> ${WRKSRC}/KeePass

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/KeePass ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.* ${DESTDIR}${PREFIX}/libexec/KeePass
	${INSTALL_DATA} ${WRKSRC}/XSL/* ${DESTDIR}${PREFIX}/libexec/KeePass/XSL
	${INSTALL_DATA} ${FILESDIR}/keepass.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
