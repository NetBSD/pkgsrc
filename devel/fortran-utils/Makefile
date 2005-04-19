# $NetBSD: Makefile,v 1.10 2005/04/19 18:39:23 minskim Exp $

DISTNAME=	fortran-utils-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Utilities for Fortran programmers

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/fortran-utils

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}	\
		MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}

.include "../../mk/bsd.pkg.mk"
