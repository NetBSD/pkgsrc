# $NetBSD: Makefile,v 1.12 2005/04/06 15:02:05 adam Exp $

DISTNAME=	dbh-1.0.24
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbh/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dbh.sourceforge.net/
COMMENT=	Library to create disk based Hashtables

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh/html
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog \
		${PREFIX}/share/doc/dbh
	cd ${WRKSRC} && ${INSTALL_DATA} doc/dbh-hash-tables.html \
		${PREFIX}/share/doc/dbh/html

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
