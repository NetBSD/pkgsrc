# $NetBSD: Makefile,v 1.4 2004/01/20 12:26:50 agc Exp $

DISTNAME=	rus-ispell-0.99f5
PKGNAME=	ispell-russian-0.99.5
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
		@${ECHO} '  To enable native "YO" letter support please use'
		@${ECHO} '  "make YO=yes" when building this package.'
		@${ECHO} ''
		@${ECHO} '===================================================='

.include "../../mk/bsd.pkg.mk"
