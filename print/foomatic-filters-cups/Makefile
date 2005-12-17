# $NetBSD: Makefile,v 1.1.1.1 2005/12/17 18:26:15 jlam Exp $

.include "../../print/foomatic-filters/Makefile.common"

DISTNAME=	foomatic-filters-cups-${FOOMATIC_FILTERS_VERSION}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Foomatic support for CUPS

DEPENDS+=	cups>=1.0:../../print/cups
DEPENDS+=	foomatic-filters-${FOOMATIC_FILTERS_VERSION}{,nb[0-9]*}:../../print/foomatic-filters

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

EVAL_PREFIX+=		CUPS_PREFIX=cups
CUPS_FILTERDIR=		${CUPS_PREFIX:Q}/libexec/cups/filter
FILES_SUBST+=		CUPS_FILTERDIR=${CUPS_FILTERDIR}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL

do-build:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
