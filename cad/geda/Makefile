# $NetBSD: Makefile,v 1.32 2004/02/22 20:37:45 dmcmahill Exp $
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

DEPENDS+=	gschem-${PKGVERSION}nb2:../../cad/gschem
DEPENDS+=	gnetlist-${PKGVERSION}nb2:../../cad/gnetlist
DEPENDS+=	gsymcheck-${PKGVERSION}nb2:../../cad/gsymcheck
DEPENDS+=	geda-utils-${PKGVERSION}nb2:../../cad/geda-utils
DEPENDS+=	geda-docs-${PKGVERSION}:../../cad/geda-docs
DEPENDS+=	geda-examples-${PKGVERSION}:../../cad/geda-examples

.include "Makefile.common"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../cad/libgeda/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
