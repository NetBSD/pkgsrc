# $NetBSD: Makefile,v 1.3 2001/02/16 14:17:23 wiz Exp $

DISTNAME=	freetds-0.50
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.metalab.unc.edu/pub/Linux/ALPHA/freetds/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/freetds
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

WRKSRC=		${WRKDIR}/freetds

#post-install:
#	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db

.include "../../mk/bsd.pkg.mk"
