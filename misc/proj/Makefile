# $NetBSD: Makefile,v 1.4 2001/04/20 20:38:16 jtb Exp $

DISTNAME=		proj-4.4.3
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} proj-pdf-docs.tar.gz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		Cartographic projection software

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proj
	${INSTALL_DATA} ${WRKDIR}/*.pdf ${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
