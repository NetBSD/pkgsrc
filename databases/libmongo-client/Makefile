# $NetBSD: Makefile,v 1.5 2021/12/08 16:01:48 adam Exp $

DISTNAME=	libmongo-client-0.1.8
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	https://github.com/algernon/libmongo-client/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
