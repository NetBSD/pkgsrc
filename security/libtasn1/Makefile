# $NetBSD: Makefile,v 1.12 2004/10/03 00:18:10 tv Exp $

DISTNAME=	libtasn1-0.2.10
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gnutls/libtasn1/ \
		http://www.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-security/gnutls/libtasn1/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
