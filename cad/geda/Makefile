# $NetBSD: Makefile,v 1.30 2004/01/03 18:49:34 reed Exp $
#

DISTNAME=	geda-${PKGVERSION}
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
		ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
		http://www.geda.seul.org/devel/${PKGVERSION}/ \
		http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Toolset for automating electronic design

DEPENDS+=	gschem-${PKGVERSION}:../../cad/gschem
DEPENDS+=	gnetlist-${PKGVERSION}:../../cad/gnetlist
DEPENDS+=	gsymcheck-${PKGVERSION}:../../cad/gsymcheck
DEPENDS+=	geda-utils-${PKGVERSION}:../../cad/geda-utils
DEPENDS+=	geda-docs-${PKGVERSION}:../../cad/geda-docs
DEPENDS+=	geda-examples-${PKGVERSION}:../../cad/geda-examples

DIST_SUBDIR=	geda
PKGVERSION=	20030901

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../cad/libgeda/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
