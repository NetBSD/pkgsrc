# $NetBSD: Makefile,v 1.23 2003/12/13 00:45:21 wiz Exp $
#

DISTNAME=		libgeda-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Library of shared modules for gEDA

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20030901

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

INFO_FILES=		libgedadoc.info

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/libstroke/buildlink2.mk"
.include "../../graphics/libgdgeda/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
