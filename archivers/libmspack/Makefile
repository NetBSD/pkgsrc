# $NetBSD: Makefile,v 1.7 2019/08/05 13:39:24 prlw1 Exp $

DISTNAME=	libmspack-0.10.1alpha
CATEGORIES=	devel
MASTER_SITES=	https://www.cabextract.org.uk/libmspack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cabextract.org.uk/libmspack/
COMMENT=	Archiver for Microsoft format CAB, CHM, WIM, LIT, HLP, KWAJ and SZDD
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libmspack.pc.in

.include "../../mk/bsd.pkg.mk"
