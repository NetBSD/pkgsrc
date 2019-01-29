# $NetBSD: Makefile,v 1.2 2019/01/29 06:19:36 markd Exp $

DISTNAME=	changes
PKGNAME=	tex-${DISTNAME}-3.1.1
TEXLIVE_REV=	49448

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/changes
COMMENT=	Manual change markup
LICENSE=	lppl-1.3c

DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-truncate-[0-9]*:../../print/tex-truncate
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

REPLACE_PYTHON+=	${WRKSRC}/scripts/changes/pyMergeChanges.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
