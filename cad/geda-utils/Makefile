# $NetBSD: Makefile,v 1.9 2002/12/13 05:19:48 dmcmahill Exp $
#

DISTNAME=		geda-utils-${PKGVERSION}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Set of utilites for gEDA

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20021103

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		YES
REPLACE_PERL+=		scripts/gschupdate \
			scripts/gsymupdate \
			scripts/sarlacc_sym

.include "../../cad/libgeda/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
