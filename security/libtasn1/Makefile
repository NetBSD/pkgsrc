# $NetBSD: Makefile,v 1.4 2003/12/05 23:16:20 xtraeme Exp $
#

DISTNAME=	libtasn1-0.2.6
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
