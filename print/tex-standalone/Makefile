# $NetBSD: Makefile,v 1.7 2025/05/10 23:25:35 markd Exp $

DISTNAME=	standalone
PKGNAME=	tex-${DISTNAME}-1.5a
TEXLIVE_REV=	74247

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
