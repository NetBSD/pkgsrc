# $NetBSD: Makefile,v 1.1.1.1 2004/11/05 22:30:37 wiz Exp $
#

DISTNAME=		libvisual-gforce-0.1.1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		G-Force libvisual plugin

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../audio/libvisual/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
