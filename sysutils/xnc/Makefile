# $NetBSD: Makefile,v 1.16 2004/04/25 03:14:44 snj Exp $

DISTNAME=	xnc-5.0.4.src
PKGNAME=	xnc-5.0.4
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.xnc.dubna.su/src-5/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://xnc.dubna.su/
COMMENT=	File manager for X Window

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=	yes
USE_DIRS+=	xdg-1.1
USE_X11=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
