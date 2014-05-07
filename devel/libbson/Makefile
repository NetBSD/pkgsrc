# $NetBSD: Makefile,v 1.1 2014/05/07 15:43:59 fhajny Exp $

DISTNAME=	libbson-0.6.8
CATEGORIES=	devel
MASTER_SITES=	http://github.com/mongodb/libbson/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/mongodb/libbson/
COMMENT=	BSON utility library
LICENSE=	apache-2.0

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libbson-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
