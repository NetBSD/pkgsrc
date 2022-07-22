# $NetBSD: Makefile,v 1.8 2022/07/22 22:25:08 wiz Exp $

DISTNAME=	libmspack-0.10.1alpha
CATEGORIES=	devel
MASTER_SITES=	https://www.cabextract.org.uk/libmspack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cabextract.org.uk/libmspack/
COMMENT=	Archiver for Microsoft format CAB, CHM, WIM, LIT, HLP, KWAJ and SZDD
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libmspack.pc.in

.include "../../mk/bsd.pkg.mk"
