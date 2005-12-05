# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:03 rillig Exp $

DISTNAME=	fortran-utils-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Utilities for Fortran programmers

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/fortran-utils

MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} BINMODE=${BINMODE:Q}	\
		MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q} MANMODE=${MANMODE:Q}

.include "../../mk/bsd.pkg.mk"
