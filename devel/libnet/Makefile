# $NetBSD: Makefile,v 1.36 2021/07/22 07:58:50 wiz Exp $

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

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
