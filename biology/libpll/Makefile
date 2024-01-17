# $NetBSD: Makefile,v 1.2 2024/01/17 15:53:51 thor Exp $

DISTNAME=	libpll-src-0.3.2
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=xflouris/}
GITHUB_PROJECT=	libpll
GITHUB_RELEASE=	0.3.2

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/xflouris/libpll/
COMMENT=	High-performance software library for phylogenetic analysis
LICENSE=	gnu-agpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	bison flex

CONFIGURE_ARGS+=	--disable-pdfman

.include "../../mk/bsd.pkg.mk"
