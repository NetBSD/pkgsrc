# $NetBSD: Makefile,v 1.8 2001/09/27 23:17:46 jlam Exp $
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
DEPENDS+=		libgdgeda>=1.8:../../graphics/libgdgeda
DEPENDS+=		gtk+>=1.2.3:../../x11/gtk

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20010708

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
