# $NetBSD: Makefile,v 1.1.1.1 2000/02/23 01:29:52 wiz Exp $
#

DISTNAME=	its4-1.0
CATEGORIES=	devel
MASTER_SITES=	# have to fetch for yourself, or from a NetBSD mirror
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.rstcorp.com/its4/

LICENSE=        no-commercial-use

USE_CONFIGURE=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/its4

do-configure:
	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/its4 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/its4.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/its4
	cd ${WRKSRC} && ${INSTALL_DATA} LICENCE TODO vulns.i4d \
		${PREFIX}/share/its4

.include "../../mk/bsd.pkg.mk"
