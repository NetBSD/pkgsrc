# $NetBSD: Makefile,v 1.2 2000/11/07 20:32:26 skrll Exp $

DISTNAME=	freetds-0.50
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.metalab.unc.edu/pub/Linux/ALPHA/freetds/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.freetds.org/

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/freetds
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

WRKSRC=		${WRKDIR}/freetds

#post-install:
#	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db

.include "../../mk/bsd.pkg.mk"
