# $NetBSD: Makefile,v 1.7 2003/07/21 16:51:42 martti Exp $
#

DISTNAME=	libmng-1.0.5
PKGNAME=	${DISTNAME:S/libmng/gmngview/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/gcc/gtk-mng-view
CATEGORIES=	graphics
MASTER_SITES=	http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Simple GTK-based MNG viewer

USE_BUILDLINK2=	YES
MAKE_ENV+=	LIBMNG_PREFIX=${BUILDLINK_PREFIX.mng:Q}

EXTRACT_ELEMENTS=	*/contrib/gcc/gtk-mng*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmngview ${PREFIX}/bin

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
