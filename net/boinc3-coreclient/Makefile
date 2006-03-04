# $NetBSD: Makefile,v 1.4 2006/03/04 21:30:17 jlam Exp $
#

#DISTNAME=		boinc-3.07
DISTNAME=		boinc_public-cvs-2004-07-14
# in the source: 3.20
PKGNAME=		boinc3-coreclient-3.19.20040714
CATEGORIES=		net
#MASTER_SITES=		http://boinc.berkeley.edu/source/archive/
MASTER_SITES=		http://boinc.berkeley.edu/source/nightly/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://boinc.berkeley.edu/
COMMENT=		Core client for Boinc V3

WRKSRC=		${WRKDIR}/boinc_public

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		MYSQL_CONFIG=true

BUILDDIRS=	RSAEuro client

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}; for d in ${BUILDDIRS}; do \
		(cd $$d && ${SETENV} ${MAKE_ENV} ${MAKE}); \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/client/boinc_client \
		${PREFIX}/bin/boinc3_coreclient

.include "../../mk/bsd.pkg.mk"
