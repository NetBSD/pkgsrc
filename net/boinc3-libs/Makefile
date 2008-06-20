# $NetBSD: Makefile,v 1.5 2008/06/20 01:09:29 joerg Exp $
#

#DISTNAME=		boinc-3.07
DISTNAME=		boinc_public-cvs-2004-07-14
# in the source: 3.20
PKGNAME=		boinc3-libs-3.19.20040714
CATEGORIES=		net
#MASTER_SITES=		http://boinc.berkeley.edu/source/archive/
MASTER_SITES=		http://boinc.berkeley.edu/source/nightly/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://boinc.berkeley.edu/
COMMENT=		Libraries for BOINC applications

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/boinc_public
PATCHDIR=	${.CURDIR}/../../net/boinc3-coreclient/patches
DISTINFO_FILE=	${.CURDIR}/../../net/boinc3-coreclient/distinfo

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		MYSQL_CONFIG=true

USE_LANGUAGES=	c c++

BUILDDIRS=	RSAEuro lib api

INSTALLATION_DIRS=	boinc3/lib boinc3/api

do-build:
	cd ${WRKSRC}; for d in ${BUILDDIRS}; do \
		(cd $$d && ${SETENV} ${MAKE_ENV} ${MAKE}); \
	done

do-install:
	${CP} ${WRKSRC}/lib/*.h ${DESTDIR}${PREFIX}/boinc3/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libboinc.a ${DESTDIR}${PREFIX}/boinc3/lib
	${CP} ${WRKSRC}/api/*.h ${DESTDIR}${PREFIX}/boinc3/api
	${INSTALL_DATA} ${WRKSRC}/api/libboinc_api.a ${DESTDIR}${PREFIX}/boinc3/api

.include "../../mk/bsd.pkg.mk"
