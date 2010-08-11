# $NetBSD: Makefile,v 1.3 2010/08/11 20:33:19 asau Exp $
#

DISTNAME=	muparser_v132
PKGNAME=	muparser-132
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=muparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://muparser.sourceforge.net/
COMMENT=	Parser for mathematical expressions
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
#USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	build/autoconf/muparser.pc.in

do-test:
	cd ${WRKSRC}/samples/example1 && echo quit | LD_LIBRARY_PATH=../../lib ./example1

.include "../../mk/bsd.pkg.mk"
