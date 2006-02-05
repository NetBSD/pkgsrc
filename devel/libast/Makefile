# $NetBSD: Makefile,v 1.19 2006/02/05 23:08:44 joerg Exp $

DISTNAME=	libast-0.6.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=  	http://www.eterm.org/download/

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/libast/?topic_id=809%2C861
COMMENT=	The Library of Assorted Spiffy Things

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
TEST_TARGET=		test

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=-lresolv
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
