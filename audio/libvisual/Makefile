# $NetBSD: Makefile,v 1.2 2004/11/12 20:18:27 kristerw Exp $
#

DISTNAME=		libvisual-0.1.7
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Abstraction library between applications and audio visualisation plugins

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes

# Remove option that gcc 2.95 does not understand.
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-variable

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
