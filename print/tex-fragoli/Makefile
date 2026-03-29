# $NetBSD: Makefile,v 1.2 2026/03/29 03:48:24 markd Exp $

DISTNAME=	fragoli
PKGNAME=	tex-${DISTNAME}-1.2.3
TEXLIVE_REV=	76924

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fragoli
COMMENT=	Macros for constructing complex semantic derivations
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-comment-[0-9]*:../../print/tex-comment
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-units-[0-9]*:../../print/tex-units
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring
DEPENDS+=	tex-varwidth-[0-9]*:../../print/tex-varwidth

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
