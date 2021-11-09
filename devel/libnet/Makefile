# $NetBSD: Makefile,v 1.37 2021/11/09 11:56:24 nia Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-link-layer=linux
.elif exists(/usr/include/net/bpf.h)
CONFIGURE_ARGS+=	--with-link-layer=bpf
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
