# $NetBSD: Makefile,v 1.15 2017/05/19 13:29:03 prlw1 Exp $

META_PACKAGE=	yes

.include "../../print/foomatic-filters/Makefile.common"

DISTNAME=	foomatic-filters-cups-${FOOMATIC_FILTERS_VERSION}
PKGREVISION=	3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foomatic support for CUPS

DEPENDS+=	cups>=1.0:../../print/cups
DEPENDS+=	foomatic-filters-${FOOMATIC_FILTERS_VERSION}{,nb[0-9]*}:../../print/foomatic-filters

WRKSRC=		${WRKDIR}

CUPS_FILTERDIR=		${LOCALBASE}/libexec/cups/filter
FILES_SUBST+=		CUPS_FILTERDIR=${CUPS_FILTERDIR}

.include "../../mk/bsd.pkg.mk"
