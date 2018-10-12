# $NetBSD: Makefile,v 1.5 2018/10/12 13:21:24 sborrill Exp $

DISTNAME=	libmspack-0.7.1alpha
CATEGORIES=	devel
MASTER_SITES=	https://www.cabextract.org.uk/libmspack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cabextract.org.uk/libmspack/
COMMENT=	Archiver for Microsoft format CAB, CHM, WIM, LIT, HLP, KWAJ and SZDD
LICENSE=	gnu-lgpl-v2.1

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmspack.pc.in

.include "../../mk/bsd.pkg.mk"
