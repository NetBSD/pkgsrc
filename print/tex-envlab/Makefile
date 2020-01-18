# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:04 rillig Exp $

DISTNAME=	envlab
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/envlab
COMMENT=	Addresses on envelopes or mailing labels
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
