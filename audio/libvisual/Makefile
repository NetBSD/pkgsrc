# $NetBSD: Makefile,v 1.4 2005/03/15 20:28:25 rillig Exp $
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

# works with gcc-3.3, so this might have to be increased to 3.3
GCC_REQD+=		3.0

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
