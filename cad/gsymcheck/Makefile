# $NetBSD: Makefile,v 1.11 2002/12/13 05:19:51 dmcmahill Exp $
#

DISTNAME=		geda-gsymcheck-${PKGVERSION}
PKGNAME=		gsymcheck-${PKGVERSION}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		EDA (Electronic Design Automation) symbol checker

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20021103

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../cad/libgeda/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
