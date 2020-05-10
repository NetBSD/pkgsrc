# $NetBSD: Makefile,v 1.9 2020/05/10 04:31:56 markd Exp $

DISTNAME=	zapfding
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Dingbat typeface designed by Hermann Zapf
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	uzd.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
