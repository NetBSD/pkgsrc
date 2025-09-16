# $NetBSD: Makefile,v 1.43 2025/09/16 20:25:18 gutteridge Exp $

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

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
