# $NetBSD: Makefile,v 1.1 2014/08/12 15:53:36 fhajny Exp $

DISTNAME=	libmongo-client-0.1.8
CATEGORIES=	databases
MASTER_SITES=	https://github.com/algernon/libmongo-client/archive/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/algernon/libmongo-client/
COMMENT=	Alternative C driver for MongoDB
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/libmongo-client-${DISTNAME}

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoreconf automake pkg-config

GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	src/libmongo-client.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
