# $NetBSD: Makefile,v 1.10 2002/05/18 18:08:47 dmcmahill Exp $
#

DISTNAME=		libgeda-${PKGVERSION}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Library of shared modules for gEDA

DEPENDS+=		guile>=1.3.0:../../lang/guile
DEPENDS+=		libstroke-[0-9]*:../../devel/libstroke
DEPENDS+=		libgdgeda>=1.8nb1:../../graphics/libgdgeda
DEPENDS+=		gtk+>=1.2.3:../../x11/gtk

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20020414

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
