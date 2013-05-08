# $NetBSD: Makefile,v 1.5 2013/05/08 17:40:30 shattered Exp $
#

DISTNAME=	lhasa-0.1.0
CATEGORIES=	archivers
MASTER_SITES=	http://www.soulsphere.org/projects/lhasa/

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
