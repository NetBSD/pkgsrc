# $NetBSD: Makefile,v 1.1.1.1 2004/07/19 20:11:04 drochner Exp $
#

#DISTNAME=		boinc-3.07
DISTNAME=		boinc_public-cvs-2004-07-14
# in the source: 3.20
PKGNAME=		boinc3-libs-3.19.20040714
CATEGORIES=		net
#MASTER_SITES=		http://boinc.berkeley.edu/source/archive/
MASTER_SITES=		http://boinc.berkeley.edu/source/nightly/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://boinc.berkeley.edu/
COMMENT=		Libraries for BOINC applications

WRKSRC=		${WRKDIR}/boinc_public
PATCHDIR=	${.CURDIR}/../../net/boinc3-coreclient/patches
DISTINFO_FILE=	${.CURDIR}/../../net/boinc3-coreclient/distinfo

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		MYSQL_CONFIG=true

BUILDDIRS=	RSAEuro lib api

do-build:
	cd ${WRKSRC}; for d in ${BUILDDIRS}; do \
		(cd $$d && ${SETENV} ${MAKE_ENV} ${MAKE}); \
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/boinc3/lib
	${CP} ${WRKSRC}/lib/*.h ${PREFIX}/boinc3/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libboinc.a ${PREFIX}/boinc3/lib
	${INSTALL_DATA_DIR} ${PREFIX}/boinc3/api
	${CP} ${WRKSRC}/api/*.h ${PREFIX}/boinc3/api
	${INSTALL_DATA} ${WRKSRC}/api/libboinc_api.a ${PREFIX}/boinc3/api

.include "../../mk/bsd.pkg.mk"
