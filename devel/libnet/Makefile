# $NetBSD: Makefile,v 1.34 2021/07/21 22:25:54 khorben Exp $

DISTNAME=	libnet-1.2
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_GITHUB:=libnet/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codedocs.xyz/libnet/libnet/
COMMENT=	C library for portable packet creation and injection
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--disable-doxygen-doc

.include "../../mk/bsd.pkg.mk"
