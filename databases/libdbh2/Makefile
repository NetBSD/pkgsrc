# $NetBSD: Makefile,v 1.1 2015/01/19 02:07:41 mef Exp $

DISTNAME=	libdbh2-5.0.16
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbh.sourceforge.net/
COMMENT=	Library to create disk based Hashtables
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	share/doc/dbh/html

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog \
	    ${DESTDIR}${PREFIX}/share/doc/dbh

.include "../../mk/bsd.pkg.mk"
