# $NetBSD: Makefile,v 1.2 2001/02/17 17:49:48 wiz Exp $

DISTNAME=	libdes-4.04b
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.psy.uq.oz.au/pub/Crypto/DES/

MAINTAINER=	refling@comet.lbl.gov
COMMENT=	Small DES (Data Encryption Standard) lib & standalone program

CRYPTO=		YES

WRKSRC=         ${WRKDIR}/des

MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/bsd.pkg.mk"
