# $NetBSD: Makefile,v 1.44 2026/04/20 05:56:57 wiz Exp $

DISTNAME=		udunits-2.2.26
PKGREVISION=		1
CATEGORIES=		math devel
MASTER_SITES=		ftp://ftp.unidata.ucar.edu/pub/udunits/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.unidata.ucar.edu/software/udunits/
COMMENT=		Library and program for manipulating units of physical quantities
LICENSE=		ucar-license

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES+=		c

CFLAGS+=		-Wno-implicit-function-declaration

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
