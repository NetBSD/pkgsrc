# $NetBSD: Makefile,v 1.12 2014/06/18 09:26:11 wiz Exp $

META_PACKAGE=	yes

.include "../../print/foomatic-ppds/Makefile.common"

DISTNAME=	foomatic-ppds-cups-${FOOMATIC_PPDS_VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foomatic PPD collection for CUPS servers

DEPENDS+=	cups>=1.0:../../print/cups15
DEPENDS+=	foomatic-ppds-${FOOMATIC_PPDS_VERSION}{,nb[0-9]*}:../../print/foomatic-ppds

WRKSRC=		${WRKDIR}

EVAL_PREFIX+=		CUPS_PREFIX=cups
CUPS_DATADIR=		${CUPS_PREFIX:Q}/share/cups/model
FILES_SUBST+=		CUPS_DATADIR=${CUPS_DATADIR}

.include "../../mk/bsd.pkg.mk"
