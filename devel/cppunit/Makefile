# $NetBSD: Makefile,v 1.26 2017/04/19 12:20:08 wiz Exp $

DISTNAME=	cppunit-1.14.0
CATEGORIES=	devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/cppunit
COMMENT=	C++ unit testing framework
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	cppunit.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
