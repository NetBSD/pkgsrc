# $NetBSD: Makefile,v 1.15 2003/05/02 11:53:58 wiz Exp $
#

DISTNAME=		libgeda-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Library of shared modules for gEDA

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20030223

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libstroke/buildlink2.mk"
.include "../../graphics/libgdgeda/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
