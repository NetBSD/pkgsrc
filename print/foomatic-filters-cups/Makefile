# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:43 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../print/foomatic-filters/Makefile.common"

DISTNAME=	foomatic-filters-cups-${FOOMATIC_FILTERS_VERSION}
PKGREVISION=	1
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Foomatic support for CUPS

DEPENDS+=	cups>=1.0:../../print/cups
DEPENDS+=	foomatic-filters-${FOOMATIC_FILTERS_VERSION}{,nb[0-9]*}:../../print/foomatic-filters

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_INSTALL=	yes
PLIST_SRC=	# empty

EVAL_PREFIX+=		CUPS_PREFIX=cups
CUPS_FILTERDIR=		${CUPS_PREFIX:Q}/libexec/cups/filter
FILES_SUBST+=		CUPS_FILTERDIR=${CUPS_FILTERDIR}

.include "../../mk/bsd.pkg.mk"
