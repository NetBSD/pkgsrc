# $NetBSD: Makefile,v 1.2 2016/06/16 04:06:11 markd Exp $

DISTNAME=	lollipop
PKGNAME=	tex-${DISTNAME}-1.06
TEXLIVE_REV=	41130

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lollipop
COMMENT=	TeX made easy
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"lollipop pdftex -translate-file=cp227.tcx *lollipop.ini\\n"

# execute AddFormat name=lualollipop engine=luatex         options="lualollipop.ini"
# execute AddFormat name=xelollipop engine=xetex         options="-etex xelollipop.ini"
# execute AddFormat name=dvilollipop mode=disabled engine=pdftex         options="-translate-file=cp227.tcx *lollipop.ini"
# execute AddFormat name=dvilualollipop mode=disabled engine=luatex         options="-translate-file=cp227.tcx lualollipop.ini"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/lollipop

.include "../../mk/bsd.pkg.mk"
