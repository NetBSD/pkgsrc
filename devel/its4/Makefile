# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=	its4-1.1.1
CATEGORIES=	devel
MASTER_SITES=	# have to fetch for yourself, or from a NetBSD mirror
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cigital.com/its4/
COMMENT=	Static C/C++ code scanner for potential security problems

LICENSE=        no-commercial-use

WRKSRC=		${WRKDIR}/its4
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/its4
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/its4 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/its4.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/its4
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE TODO vulns.i4d \
		${PREFIX}/share/its4

.include "../../mk/bsd.pkg.mk"
