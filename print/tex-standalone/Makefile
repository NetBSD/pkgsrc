# $NetBSD: Makefile,v 1.6 2023/04/03 11:51:21 markd Exp $

DISTNAME=	standalone
PKGNAME=	tex-${DISTNAME}-1.3b
TEXLIVE_REV=	64677

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/standalone
COMMENT=	Compile TeX pictures stand-alone or as part of a document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-adjustbox-[0-9]*:../../print/tex-adjustbox
DEPENDS+=	tex-currfile-[0-9]*:../../print/tex-currfile
DEPENDS+=	tex-filemod-[0-9]*:../../print/tex-filemod
DEPENDS+=	tex-gincltex-[0-9]*:../../print/tex-gincltex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
