# $NetBSD: Makefile,v 1.1.1.1 2004/03/05 14:46:23 adam Exp $
#

DISTNAME=	cln-1.1.6
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
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/cln.pc.in

INFO_FILES=	cln.info

.include "../../mk/bsd.pkg.mk"
