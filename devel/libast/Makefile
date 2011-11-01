# $NetBSD: Makefile,v 1.31 2011/11/01 06:00:57 sbd Exp $

DISTNAME=	libast-0.7
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.eterm.org/download/

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/libast/
COMMENT=	The Library of Assorted Spiffy Things

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
TEST_TARGET=		test

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=-lresolv
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
