# $NetBSD: Makefile,v 1.3 2005/02/20 15:06:17 wiz Exp $
#

DISTNAME=		libvisual-0.2.0
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
.include "../../mk/bsd.pkg.mk"
