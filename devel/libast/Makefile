# $NetBSD: Makefile,v 1.40 2016/02/25 12:12:48 jperkin Exp $

DISTNAME=	libast-0.7
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	http://www.eterm.org/download/

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/libast/
COMMENT=	The Library of Assorted Spiffy Things

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
TEST_TARGET=		test

.include "options.mk"

LDFLAGS.SunOS+=	-lresolv

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
