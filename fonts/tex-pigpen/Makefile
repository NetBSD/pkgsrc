# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:48 rillig Exp $

DISTNAME=	pigpen
PKGNAME=	tex-${DISTNAME}-0.2
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pigpen
COMMENT=	Font for the pigpen (or masonic) cipher
LICENSE=	lppl-1.3c

TEX_MIXEDMAP_FILES+=	pigpen.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
