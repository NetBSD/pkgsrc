# $NetBSD: Makefile,v 1.6 2004/02/13 13:09:43 sekiya Exp $

DISTNAME=	libtasn1-0.2.6
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIG_GUESS_OVERRIDE+=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKSRC}/config.sub

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
