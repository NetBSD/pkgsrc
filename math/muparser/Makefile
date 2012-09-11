# $NetBSD: Makefile,v 1.6 2012/09/11 23:04:24 asau Exp $
#

DISTNAME=	muparser_v2_2_2
# The "200" is nonsense, but we had a revision "134" before.
PKGNAME=	muparser-200.2.2.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=muparser/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://muparser.sourceforge.net/
COMMENT=	Parser for mathematical expressions
LICENSE=	mit

MAKE_JOBS_SAFE=	no
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
#USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	build/autoconf/muparser.pc.in

do-test:
	cd ${WRKSRC}/samples/example1 && echo quit | LD_LIBRARY_PATH=../../lib ./example1

.include "../../mk/bsd.pkg.mk"
