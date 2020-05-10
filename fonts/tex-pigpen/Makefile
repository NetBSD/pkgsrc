# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:51 markd Exp $

DISTNAME=	pigpen
PKGNAME=	tex-${DISTNAME}-0.2
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pigpen
COMMENT=	Font for the pigpen (or masonic) cipher
LICENSE=	lppl-1.3c

TEX_MIXEDMAP_FILES+=	pigpen.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
