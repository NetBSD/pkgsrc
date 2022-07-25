# $NetBSD: Makefile,v 1.10 2022/07/25 11:12:20 wiz Exp $

DISTNAME=	libvisual-0.2.0
PKGNAME=	libvisual0.2-0.2.0
PKGREVISION=	1
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://localhost.nl/~synap/libvisual-wiki/
COMMENT=	Abstraction library for applications and audio visualisation plugins
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=		libvisual<0.4.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc*)
CPPFLAGS+=		-mmmx
.endif

.include "../../mk/bsd.pkg.mk"
