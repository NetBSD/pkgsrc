# $NetBSD: Makefile,v 1.8 2004/01/20 12:18:16 agc Exp $
#

DISTNAME=	libmng-1.0.5
PKGNAME=	${DISTNAME:S/libmng/gmngview/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Simple GTK-based MNG viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/gcc/gtk-mng-view
USE_BUILDLINK2=	YES
MAKE_ENV+=	LIBMNG_PREFIX=${BUILDLINK_PREFIX.mng:Q}

EXTRACT_ELEMENTS=	*/contrib/gcc/gtk-mng*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmngview ${PREFIX}/bin

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
