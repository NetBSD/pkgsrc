# $NetBSD: Makefile,v 1.14 2007/01/11 11:49:33 joerg Exp $

DISTNAME=	jakdaw-0.0.4
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	audio xmms
MASTER_SITES=	http://www.jakdaw.ucam.org/xmms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jakdaw.ucam.org/xmms/
COMMENT=	Very customizable XMMS plugin with nice effects

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
