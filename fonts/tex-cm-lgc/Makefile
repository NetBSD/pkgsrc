# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:41 markd Exp $

DISTNAME=	cm-lgc
PKGNAME=	tex-${DISTNAME}-0.5
PKGREVISION=	1
TEXLIVE_REV=	28250

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cm-lgc
COMMENT=	Type 1 CM-based fonts for Latin, Greek and Cyrillic
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	cm-lgc.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
