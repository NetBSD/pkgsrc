# $NetBSD: Makefile,v 1.7 2002/03/14 23:57:02 wiz Exp $

DISTNAME=	freetds-0.53
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.metalab.unc.edu/pub/Linux/ALPHA/freetds/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/freetds
CONFIGURE_ARGS+=	--with-tdsver=7.0

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

#post-install:
#	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db

.include "../../mk/bsd.pkg.mk"
