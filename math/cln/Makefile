# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:01 joerg Exp $

DISTNAME=	cln-1.1.9
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gnu/ \
		ftp://ftp.santafe.edu/pub/gnu/ \
		ftp://ftp.ilog.fr/pub/Users/haible/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ginac.de/CLN/
COMMENT=	CLN Class Library for Numbers

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/cln.pc.in

INFO_FILES=	cln.info

.include "../../mk/bsd.pkg.mk"
