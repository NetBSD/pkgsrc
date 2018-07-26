# $NetBSD: Makefile,v 1.3 2018/07/26 08:37:40 wiz Exp $

DISTNAME=	libmspack-0.7alpha
CATEGORIES=	devel
MASTER_SITES=	https://www.cabextract.org.uk/libmspack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cabextract.org.uk/libmspack/
COMMENT=	Archiver for Microsoft format CAB, CHM, WIM, LIT, HLP, KWAJ and SZDD
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmspack.pc.in

.include "../../mk/bsd.pkg.mk"
