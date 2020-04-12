# $NetBSD: Makefile,v 1.17 2020/04/12 19:52:40 joerg Exp $
#

DISTNAME=		acme091src
PKGNAME=		acme-0.91
CATEGORIES=		devel
MASTER_SITES=		http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme/current/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${LIBDIST}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES.${LIBDIST}=	http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/acme-crossass/
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Extra data overflow: Need 24 bytes but only found 20 bytes
TOOLS_PLATFORM.unzip=
.endif

.include "../../mk/bsd.pkg.mk"
