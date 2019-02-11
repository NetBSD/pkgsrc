# $NetBSD: Makefile,v 1.1 2019/02/11 21:55:27 leot Exp $

DISTNAME=	libxls-1.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libxls/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/libxls/libxls
COMMENT=	Extract cell data from legacy Microsoft Excel files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
