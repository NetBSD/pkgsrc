# $NetBSD: Makefile,v 1.6 2025/05/08 08:15:44 markd Exp $

DISTNAME=	texsis
PKGNAME=	tex-${DISTNAME}-2.18.69742
TEXLIVE_REV=	69742

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texsis
COMMENT=	Plain TeX macros for Physicists
LICENSE=	lppl-1.3c

DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"texsis pdftex - -translate-file=cp227.tcx texsis.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/texsis

.include "../../mk/bsd.pkg.mk"
