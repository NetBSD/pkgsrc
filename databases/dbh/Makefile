# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 13:45:39 hubertf Exp $

DISTNAME=		dbh_1.0-14
PKGNAME=		dbh-1.0.14
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dbh/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://dbh.sourceforge.net/
COMMENT=		Library to create disk based Hashtables

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/src/dbh-1.0.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh/
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog \
		${PREFIX}/share/doc/dbh/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh/html/
	cd ${WRKSRC} && ${INSTALL_DATA} doc/dbh-hash-tables.html \
		${PREFIX}/share/doc/dbh/html/

.include "../../mk/bsd.pkg.mk"
