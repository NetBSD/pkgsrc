# $NetBSD: Makefile,v 1.6 2004/03/10 09:46:50 xtraeme Exp $

DISTNAME=		dbh_1.0-15
PKGNAME=		dbh-1.0.15
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dbh/}

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://dbh.sourceforge.net/
COMMENT=		Library to create disk based Hashtables

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/dbh-1.0.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh/html
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog \
		${PREFIX}/share/doc/dbh
	cd ${WRKSRC} && ${INSTALL_DATA} doc/dbh-hash-tables.html \
		${PREFIX}/share/doc/dbh/html

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
