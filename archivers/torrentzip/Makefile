# $NetBSD: Makefile,v 1.7 2020/10/05 15:21:07 wiz Exp $

DISTNAME=	TrrntZip.NET106
PKGNAME=	torrentzip-1.0.6
CATEGORIES=	archivers
MASTER_SITES=	https://romvault.com/trrntzip/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://romvault.com/trrntzip/
COMMENT=	Convert zip archives to torrentzip format
LICENSE=	apache-2.0

DEPENDS+=	mono-[0-9]*:../../lang/mono6

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin libexec/torrentzip

do-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/torrentzip
	${ECHO} "${PREFIX}/bin/mono ${PREFIX}/libexec/torrentzip/TrrntZip.NET.exe "'"$$@"' >> ${WRKSRC}/torrentzip

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/torrentzip ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/TrrntZip.NET.exe ${DESTDIR}${PREFIX}/libexec/torrentzip

.include "../../mk/bsd.pkg.mk"
