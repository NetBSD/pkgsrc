# $NetBSD: Makefile,v 1.4 2018/06/03 01:27:21 markd Exp $

DISTNAME=	lollipop
PKGNAME=	tex-${DISTNAME}-1.07
PKGREVISION=	1
TEXLIVE_REV=	41438

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lollipop
COMMENT=	TeX made easy
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"lollipop tex - lollipop.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf tex ${DESTDIR}${PREFIX}/bin/lollipop

.include "../../mk/bsd.pkg.mk"
