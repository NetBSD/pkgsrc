# $NetBSD: Makefile,v 1.1.1.1 2000/01/02 21:59:48 rh Exp $
#

DISTNAME=		libgeda-${PKGVERSION}
WRKSRC=			${WRKDIR}/libgeda
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/

DEPENDS+=		guile>=1.3.0:../../lang/guile
DEPENDS+=		libstroke-*:../../devel/libstroke
DEPENDS+=		libgdgeda-*:../../graphics/libgdgeda
DEPENDS+=		gtk+>=1.2.0:../../x11/gtk

DIST_SUBDIR=		geda
PKGVERSION=		19991011

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
