# $NetBSD: Makefile,v 1.42 2021/06/23 19:54:03 bacon Exp $

DISTNAME=		udunits-2.2.26
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
