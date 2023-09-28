# $NetBSD: Makefile,v 1.4 2023/09/28 21:43:10 joerg Exp $

DISTNAME=	kvoptions
PKGNAME=	tex-${DISTNAME}-3.15
PKGREVISION=	1
TEXLIVE_REV=	63622

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kvoptions
COMMENT=	Key value format for package options
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
