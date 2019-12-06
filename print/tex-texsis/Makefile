# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:29 markd Exp $

DISTNAME=	texsis
PKGNAME=	tex-${DISTNAME}-2.18
PKGREVISION=	1
TEXLIVE_REV=	31958

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texsis
COMMENT=	Plain TeX macros for Physicists
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"texsis pdftex - -translate-file=cp227.tcx texsis.ini\\n"

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/texsis

.include "../../mk/bsd.pkg.mk"
