# $NetBSD: Makefile,v 1.1.1.1 2000/11/23 13:16:10 rh Exp $

DISTNAME=	libdes-4.04b
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.psy.uq.oz.au/pub/Crypto/DES/

MAINTAINER=	refling@comet.lbl.gov

CRYPTO=		YES

WRKSRC=         ${WRKDIR}/des

MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/bsd.pkg.mk"
