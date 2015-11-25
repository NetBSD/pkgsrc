# $NetBSD: Makefile,v 1.14 2015/11/25 12:53:09 jperkin Exp $

META_PACKAGE=	yes

.include "../../print/foomatic-ppds/Makefile.common"

DISTNAME=	foomatic-ppds-cups-${FOOMATIC_PPDS_VERSION}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foomatic PPD collection for CUPS servers

DEPENDS+=	cups>=1.0:../../print/cups15
DEPENDS+=	foomatic-ppds-${FOOMATIC_PPDS_VERSION}{,nb[0-9]*}:../../print/foomatic-ppds

WRKSRC=		${WRKDIR}

CUPS_DATADIR=		${LOCALBASE}/share/cups/model
FILES_SUBST+=		CUPS_DATADIR=${CUPS_DATADIR}

.include "../../mk/bsd.pkg.mk"
