# $NetBSD: Makefile,v 1.2 2019/12/06 19:32:19 markd Exp $

DISTNAME=	pigpen
PKGNAME=	tex-${DISTNAME}-0.2
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pigpen
COMMENT=	Font for the pigpen (or masonic) cipher
LICENSE=	lppl-1.3c

TEX_MIXEDMAP_FILES+=	pigpen.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
