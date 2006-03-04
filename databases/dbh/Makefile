# $NetBSD: Makefile,v 1.17 2006/03/04 21:29:08 jlam Exp $

DISTNAME=	dbh-1.0.24
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbh.sourceforge.net/
COMMENT=	Library to create disk based Hashtables

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dbh/html
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog \
		${PREFIX}/share/doc/dbh
	cd ${WRKSRC} && ${INSTALL_DATA} doc/dbh-hash-tables.html \
		${PREFIX}/share/doc/dbh/html

.include "../../mk/bsd.pkg.mk"
