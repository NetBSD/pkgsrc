# $NetBSD: Makefile,v 1.1 2015/05/16 10:30:14 markd Exp $

DISTNAME=	amstex
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	33736

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/amstex
COMMENT=	American Mathematical Society plain TeX macros
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

INSTALLATION_DIRS=	bin

TEX_FORMATS+=	"amstex pdftex -translate-file=cp227.tcx *amstex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/amstex

.include "../../mk/bsd.pkg.mk"
