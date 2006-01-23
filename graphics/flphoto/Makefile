# $NetBSD: Makefile,v 1.4 2006/01/23 17:00:05 joerg Exp $
#

DISTNAME=		flphoto-1.2-source
PKGNAME=		flphoto-1.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fltk/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.easysw.com/~mike/flphoto/index.html
COMMENT=		Image management and display program

WRKSRC=		${WRKDIR}/flphoto-1.2
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/fltk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
