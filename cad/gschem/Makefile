# $NetBSD: Makefile,v 1.22 2003/08/09 10:32:14 seb Exp $
#

DISTNAME=		geda-gschem-${PKGVERSION}
PKGNAME=		gschem-${PKGVERSION}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Schematic capture tool

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20030525

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
INFO_FILES=		gschemdoc.info

.include "../../cad/libgeda/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
