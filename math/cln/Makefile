# $NetBSD: Makefile,v 1.4 2004/11/29 08:47:29 adam Exp $

DISTNAME=	cln-1.1.9
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gnu/ \
		ftp://ftp.santafe.edu/pub/gnu/ \
		ftp://ftp.ilog.fr/pub/Users/haible/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ginac.de/CLN/
COMMENT=	CLN Class Library for Numbers

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/cln.pc.in

INFO_FILES=	cln.info

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
