# $NetBSD: Makefile,v 1.8 2005/07/21 16:29:43 wiz Exp $
#

DISTNAME=		libvisual-0.2.0
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Abstraction library between applications and audio visualisation plugins

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
