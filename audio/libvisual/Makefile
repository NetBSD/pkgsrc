# $NetBSD: Makefile,v 1.12 2006/05/13 12:33:04 joerg Exp $
#

DISTNAME=		libvisual-0.2.0
PKGREVISION=		1
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Abstraction library between applications and audio visualisation plugins

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
