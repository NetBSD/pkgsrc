# $NetBSD: Makefile,v 1.7 2015/08/26 21:25:31 shattered Exp $

DISTNAME=	lhasa-0.3.0
CATEGORIES=	archivers
MASTER_SITES=	https://soulsphere.org/projects/lhasa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fragglet.github.com/lhasa/
COMMENT=	Freely licensed lha archiving tool (for .lzh and .lha files)
LICENSE=	isc

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	liblhasa.pc.in
TEST_TARGET=		check

CONFLICTS=		lha-[0-9]*

.include "../../mk/bsd.pkg.mk"
