# $NetBSD: Makefile,v 1.16 2017/05/19 13:29:03 prlw1 Exp $

META_PACKAGE=	yes

.include "../../print/foomatic-ppds/Makefile.common"

DISTNAME=	foomatic-ppds-cups-${FOOMATIC_PPDS_VERSION}
PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foomatic PPD collection for CUPS servers

DEPENDS+=	cups>=1.0:../../print/cups
DEPENDS+=	foomatic-ppds-${FOOMATIC_PPDS_VERSION}{,nb[0-9]*}:../../print/foomatic-ppds

WRKSRC=		${WRKDIR}

CUPS_DATADIR=		${LOCALBASE}/share/cups/model
FILES_SUBST+=		CUPS_DATADIR=${CUPS_DATADIR}

.include "../../mk/bsd.pkg.mk"
