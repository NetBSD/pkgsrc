# $NetBSD: Makefile,v 1.13 2012/12/12 10:12:16 wiz Exp $
#

DISTNAME=	acme091src
PKGNAME=	acme-0.91
CATEGORIES=	devel
MASTER_SITES=	http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LIBDIST}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
SITES.${LIBDIST}=	http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme
COMMENT=	Cross assembler for 6502, 65c02, and 65816
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax unzip

LIBDIST=	ACME_Lib2.zip
WRKSRC=		${WRKDIR}/acme091
BUILD_DIRS=	src

ACME_LIB=	${PREFIX}/share/acme
MAKE_ENV+=	ACME_LIB=${ACME_LIB:Q}

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/acme
INSTALLATION_DIRS+=	share/doc/acme

post-extract:
	cd ${WRKDIR} && unzip -qa ${_DISTDIR}/${LIBDIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/acme ${DESTDIR}${PREFIX}/bin/acme
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/acme
	cd ${WRKDIR}/ACME_Lib && pax -rw . ${DESTDIR}${ACME_LIB}

.include "../../mk/bsd.pkg.mk"
