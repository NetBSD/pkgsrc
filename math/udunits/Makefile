# $NetBSD: Makefile,v 1.41 2020/08/08 21:55:54 brook Exp $

DISTNAME=		udunits-2.2.26
CATEGORIES=		math devel
MASTER_SITES=		ftp://ftp.unidata.ucar.edu/pub/udunits/

MAINTAINER=		bacon@NetBSD.org
HOMEPAGE=		https://www.unidata.ucar.edu/software/udunits/
COMMENT=		Library and program for manipulating units of physical quantities
LICENSE=		ucar-license

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES+=		c

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
