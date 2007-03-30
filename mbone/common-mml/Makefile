# $NetBSD: Makefile,v 1.16 2007/03/30 15:41:02 joerg Exp $
#

DISTNAME=	common-1.2.16
PKGNAME=	common-mml-1.2.16
PKGREVISION=	2
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/

MAINTAINER=	psham@cs.nmsu.edu
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/
COMMENT=	Common multimedia library required by mbone tools

WRKSRC=		${WRKDIR}/common
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include/common-mml lib share/doc/common-mml

INCDIR=		${PREFIX}/include/common-mml
DOCDIR=		${PREFIX}/share/doc/common-mml

do-install:
	${LIBTOOL} --mode=install \
		${INSTALL_LIB} ${WRKSRC}/src/*.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
