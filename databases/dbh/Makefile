# $NetBSD: Makefile,v 1.20 2012/10/02 21:25:16 asau Exp $

DISTNAME=	dbh-1.0.24
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbh.sourceforge.net/
COMMENT=	Library to create disk based Hashtables

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	share/doc/dbh/html

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog \
	    ${DESTDIR}${PREFIX}/share/doc/dbh
	cd ${WRKSRC} && ${INSTALL_DATA} doc/dbh-hash-tables.html \
	    ${DESTDIR}${PREFIX}/share/doc/dbh/html

.include "../../mk/bsd.pkg.mk"
