# $NetBSD: Makefile,v 1.19 2023/07/24 19:25:36 bsiegert Exp $

META_PACKAGE=	yes

.include "../../print/foomatic-filters/Makefile.common"

DISTNAME=	foomatic-filters-cups-${FOOMATIC_FILTERS_VERSION}
PKGREVISION=	4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foomatic support for CUPS

DEPENDS+=	cups-base>=1.0:../../print/cups-base
DEPENDS+=	foomatic-filters-${FOOMATIC_FILTERS_VERSION}{,nb[0-9]*}:../../print/foomatic-filters

WRKSRC=		${WRKDIR}

CUPS_FILTERDIR=		${LOCALBASE}/libexec/cups/filter
FILES_SUBST+=		CUPS_FILTERDIR=${CUPS_FILTERDIR}

.include "../../mk/bsd.pkg.mk"
