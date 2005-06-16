# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:58 jlam Exp $
#

DISTNAME=	libmng-1.0.7
PKGNAME=	${DISTNAME:S/libmng/gmngview/}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Simple GTK-based MNG viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/gcc/gtk-mng-view
MAKE_ENV+=	LIBMNG_PREFIX=${BUILDLINK_PREFIX.mng:Q}

EXTRACT_ELEMENTS=	*/contrib/gcc/gtk-mng*
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmngview ${PREFIX}/bin

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
