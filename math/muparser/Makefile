# $NetBSD: Makefile,v 1.9 2020/03/20 11:58:00 nia Exp $
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
	cd ${WRKSRC}/samples/example1 && ${ECHO} quit | LD_LIBRARY_PATH=../../lib ./example1

.include "../../mk/bsd.pkg.mk"
