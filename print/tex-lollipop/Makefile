# $NetBSD: Makefile,v 1.6 2020/01/18 23:34:26 rillig Exp $

DISTNAME=	lollipop
PKGNAME=	tex-${DISTNAME}-1.07
PKGREVISION=	1
TEXLIVE_REV=	41438

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lollipop
COMMENT=	TeX made easy
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"lollipop tex - lollipop.ini\\n"

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf tex ${DESTDIR}${PREFIX}/bin/lollipop

.include "../../mk/bsd.pkg.mk"
