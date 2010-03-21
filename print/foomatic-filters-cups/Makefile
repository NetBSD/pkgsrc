# $NetBSD: Makefile,v 1.10 2010/03/21 16:29:42 wiz Exp $

META_PACKAGE=	yes

.include "../../print/foomatic-filters/Makefile.common"

DISTNAME=	foomatic-filters-cups-${FOOMATIC_FILTERS_VERSION}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foomatic support for CUPS

DEPENDS+=	cups>=1.0:../../print/cups
DEPENDS+=	foomatic-filters-${FOOMATIC_FILTERS_VERSION}{,nb[0-9]*}:../../print/foomatic-filters

WRKSRC=		${WRKDIR}

EVAL_PREFIX+=		CUPS_PREFIX=cups
CUPS_FILTERDIR=		${CUPS_PREFIX:Q}/libexec/cups/filter
FILES_SUBST+=		CUPS_FILTERDIR=${CUPS_FILTERDIR}

.include "../../mk/bsd.pkg.mk"
