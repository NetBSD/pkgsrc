# $NetBSD: Makefile,v 1.14 2003/05/02 11:53:56 wiz Exp $
#

DISTNAME=		geda-utils-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Set of utilites for gEDA

CONFLICTS+=		gEDA<19991011

BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols

DIST_SUBDIR=		geda
PKGVERSION=		20030223

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		YES
REPLACE_PERL+=		scripts/gschupdate \
			scripts/gsymupdate \
			scripts/refdes_renum \
			scripts/sarlacc_sym

.include "../../cad/libgeda/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
