# $NetBSD: Makefile,v 1.12 2008/05/26 02:13:17 joerg Exp $
#

DISTNAME=	acme085_linux
PKGNAME=	acme-0.85
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LIBDIST}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme/acme.html
COMMENT=	Cross assembler for 6502, 65c02, and 65816

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=	pax unzip

WRKSRC=		${WRKTOP}/sources
LIBDIST=	lib002.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKTOP=		${WRKDIR}/acme085

ACME_LIB=	${PREFIX}/share/acme
MAKE_ENV+=	ACME_LIB=${ACME_LIB:Q}

INSTALLATION_DIRS=	bin

post-extract:
	cd ${WRKDIR} && unzip -qa ${_DISTDIR}/${LIBDIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acme ${DESTDIR}${PREFIX}/bin/acme
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/acme
	${INSTALL_DATA} ${WRKTOP}/docs/* ${DESTDIR}${PREFIX}/share/doc/acme
	${INSTALL_DATA_DIR} ${DESTDIR}${ACME_LIB}
	cd ${WRKDIR}/ACME_Lib && pax -rw . ${DESTDIR}${ACME_LIB}
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${DESTDIR}${ACME_LIB}

.include "../../mk/bsd.pkg.mk"
