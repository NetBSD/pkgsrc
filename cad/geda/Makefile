# $NetBSD: Makefile,v 1.36 2004/10/03 00:13:12 tv Exp $
#

DISTNAME=	geda-${PKGVERSION}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
		ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
		http://www.geda.seul.org/devel/${PKGVERSION}/ \
		http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Toolset for automating electronic design

DEPENDS+=	gschem-${PKGVERSION}{,nb[0-9]*}:../../cad/gschem
DEPENDS+=	gnetlist-${PKGVERSION}{,nb[0-9]*}:../../cad/gnetlist
DEPENDS+=	gsymcheck-${PKGVERSION}{,nb[0-9]*}:../../cad/gsymcheck
DEPENDS+=	geda-utils-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-utils
DEPENDS+=	geda-docs-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-docs
DEPENDS+=	geda-examples-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-examples

.include "Makefile.common"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
