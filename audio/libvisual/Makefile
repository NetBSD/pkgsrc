# $NetBSD: Makefile,v 1.14 2006/07/03 23:33:43 wiz Exp $
#

DISTNAME=		libvisual-0.4.0
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://localhost.nl/~synap/libvisual/
COMMENT=		Abstraction library between applications and audio visualisation plugins

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc*)
CPPFLAGS+=		-mmmx
.endif

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
