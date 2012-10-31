# $NetBSD: Makefile,v 1.4 2012/10/31 11:19:40 asau Exp $
#

DISTNAME=	rscode-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rscode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rscode.sourceforge.net/
COMMENT=	Reed Solomon error correction code library

INSTALLATION_DIRS=	bin lib share/doc/rscode

do-install:
	${INSTALL_LIB} ${WRKSRC}/libecc.a ${DESTDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/example ${DESTDIR}${PREFIX}/bin/rscode
	${INSTALL_DATA} ${WRKSRC}/rs.doc ${DESTDIR}${PREFIX}/share/doc/rscode/

.include "../../mk/bsd.pkg.mk"
