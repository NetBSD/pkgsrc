# $NetBSD: Makefile,v 1.2 2003/06/02 01:17:16 jschauma Exp $
#

DISTNAME=	libtasn1-0.2.4
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
