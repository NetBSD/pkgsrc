# $NetBSD: Makefile,v 1.1.1.1 2002/11/19 15:53:25 jschauma Exp $

DISTNAME=	rus-ispell-0.99f3
PKGNAME=	ispell-russian-0.99.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://scon155.phys.msu.su/pub/russian/ispell/

MAINTAINER=	mishka@terabyte.com.ua
COMMENT=	Russian (KOI8-R) ispell dictonary from Alexander Lebedev

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

WRKSRC=		${WRKDIR}

MAKE_ENV+=	CAT=${CAT} RM=${RM} SED=${SED} TR=${TR} UNIQ="uniq"

.ifdef YO
MAKE_ENV+=	YO="defined"
.endif

post-configure:
		@${ECHO} '===================================================='
		@${ECHO} ''
		@${ECHO} '  To enable native "YO" letter support please add'
		@${ECHO} '  "YO=yes" option to make(1) when build package.'
		@${ECHO} ''
		@${ECHO} '===================================================='

.include "../../mk/bsd.pkg.mk"
