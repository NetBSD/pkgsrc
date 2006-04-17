# $NetBSD: Makefile,v 1.22 2006/04/17 13:46:49 wiz Exp $

DISTNAME=	xnc-5.0.4.src
PKGNAME=	xnc-5.0.4
PKGREVISION=	5
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.xnc.dubna.su/src-5/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://xnc.dubna.su/
COMMENT=	File manager for X Window

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_DIRS+=	xdg-1.1
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
