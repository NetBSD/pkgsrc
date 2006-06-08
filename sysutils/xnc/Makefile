# $NetBSD: Makefile,v 1.23 2006/06/08 15:20:20 joerg Exp $

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
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt
GNU_CONFIGURE=	yes

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
