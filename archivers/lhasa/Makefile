# $NetBSD: Makefile,v 1.6 2013/12/02 20:08:06 adam Exp $

DISTNAME=	lhasa-0.2.0
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
