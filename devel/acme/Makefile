# $NetBSD: Makefile,v 1.1.1.1 2001/10/29 18:30:30 dillo Exp $
#

DISTNAME=	acme085_linux
PKGNAME=	acme-0.85
CATEGORIES=	devel
MASTER_SITES=	http://www.esw-heim.tu-clausthal.de/~marco/cpf/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LIBDIST}

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://home.pages.de/~mac_bacon/cpf/acme.html
COMMENT=	Cross assembler for 6502, 65c02, and 65816

BUILD_DEPENDS+=	unzip-*:../../archivers/unzip

LIBDIST=	lib002.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKTOP=		${WRKDIR}/acme085
WRKSRC=		${WRKTOP}/sources

ACME_LIB=	${PREFIX}/share/acme
MAKE_ENV+=	ACME_LIB=${ACME_LIB}

post-extract:
	cd ${WRKDIR} && unzip -qa ${_DISTDIR}/${LIBDIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acme ${PREFIX}/bin/acme
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/acme
	${INSTALL_DATA} ${WRKTOP}/docs/* ${PREFIX}/share/doc/acme
	${INSTALL_DATA_DIR} ${ACME_LIB}
	cd ${WRKDIR}/ACME_Lib && ${PAX} -rw . ${ACME_LIB}
	${CHOWN} -R root:wheel ${ACME_LIB}

.include "../../mk/bsd.pkg.mk"
