# $NetBSD: Makefile,v 1.15 2004/04/14 16:15:28 jmmv Exp $

DISTNAME=	xnc-5.0.4.src
PKGNAME=	xnc-5.0.4
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.xnc.dubna.su/src-5/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://xnc.dubna.su/
COMMENT=	File manager for X Window

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=	yes
USE_DIRS+=	xdg-1.1
USE_X11=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
