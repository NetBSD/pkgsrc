# $NetBSD: Makefile,v 1.2 2003/03/29 12:42:39 jmmv Exp $

DISTNAME=	rus-ispell-0.99f3
PKGNAME=	ispell-russian-0.99.3
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://scon155.phys.msu.su/pub/russian/ispell/

MAINTAINER=	mishka@terabyte.com.ua
COMMENT=	Russian (KOI8-R) ispell dictonary from Alexander Lebedev

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

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
