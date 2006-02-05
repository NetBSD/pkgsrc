# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:36 joerg Exp $

.include "../../print/foomatic-ppds/Makefile.common"

DISTNAME=	foomatic-ppds-cups-${FOOMATIC_PPDS_VERSION}
PKGREVISION=	1
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Foomatic PPD collection for CUPS servers

DEPENDS+=	cups>=1.0:../../print/cups
DEPENDS+=	foomatic-ppds-${FOOMATIC_PPDS_VERSION}{,nb[0-9]*}:../../print/foomatic-ppds

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

EVAL_PREFIX+=		CUPS_PREFIX=cups
CUPS_DATADIR=		${CUPS_PREFIX:Q}/share/cups/model
FILES_SUBST+=		CUPS_DATADIR=${CUPS_DATADIR}

DEINSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL

do-build:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
