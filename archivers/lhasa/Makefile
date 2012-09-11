# $NetBSD: Makefile,v 1.4 2012/09/11 19:46:56 asau Exp $
#

DISTNAME=	lhasa-0.0.7
CATEGORIES=	archivers
MASTER_SITES=	http://cloud.github.com/downloads/fragglet/lhasa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fragglet.github.com/lhasa/
COMMENT=	Freely licensed lha archiving tool (for .lzh and .lha files)
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check

CONFLICTS=	lha-[0-9]*

PKGCONFIG_OVERRIDE=  liblhasa.pc.in

.include "../../mk/bsd.pkg.mk"
