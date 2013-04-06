# $NetBSD: Makefile,v 1.6 2013/04/06 03:45:07 rodent Exp $
#

DISTNAME=	libvisual-0.2.0
PKGNAME=	libvisual0.2-0.2.0
PKGREVISION=	1
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://localhost.nl/~synap/libvisual-wiki/
COMMENT=	Abstraction library for applications and audio visualisation plugins

CONFLICTS+=		libvisual<0.4.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc*)
CPPFLAGS+=		-mmmx
.endif

.include "../../mk/bsd.pkg.mk"
