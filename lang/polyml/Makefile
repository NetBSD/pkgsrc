# $NetBSD: Makefile,v 1.15 2016/03/01 19:50:10 asau Exp $

DISTNAME=	polyml.5.6
PKGNAME=	polyml-5.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyml/}

MAINTAINER=	asau@NetBSD.org
HOMEPAGE=	http://polyml.org/
COMMENT=	Poly/ML is an implementation of Standard ML

# ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc

WRKSRC=		$(WRKDIR)/$(PKGNAME_NOREV)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
TEST_TARGET=	tests

PKGCONFIG_OVERRIDE=	libpolyml/polyml.pc.in

.include "options.mk"

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
