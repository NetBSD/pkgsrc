# $NetBSD: Makefile,v 1.1.1.1 2000/05/16 01:03:47 tsarna Exp $

DISTNAME=	freetds-0.50
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.metalab.unc.edu/pub/Linux/ALPHA/freetds/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.freetds.org/

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/freetds
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/freetds

#post-install:
#	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/doc/db

.include "../../mk/bsd.pkg.mk"
