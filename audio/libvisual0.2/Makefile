# $NetBSD: Makefile,v 1.4 2009/01/04 22:32:04 shattered Exp $
#

DISTNAME=		libvisual-0.2.0
PKGNAME=		libvisual0.2-0.2.0
PKGREVISION=		1
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://localhost.nl/~synap/libvisual-wiki/
COMMENT=		Abstraction library between applications and audio visualisation plugins (0.2 branch)

PKG_DESTDIR_SUPPORT=	user-destdir

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
