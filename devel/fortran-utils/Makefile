# $NetBSD: Makefile,v 1.12 2006/03/04 21:29:15 jlam Exp $

DISTNAME=	fortran-utils-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utilities for Fortran programmers

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/fortran-utils

MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} BINMODE=${BINMODE:Q}	\
		MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q} MANMODE=${MANMODE:Q}

.include "../../mk/bsd.pkg.mk"
