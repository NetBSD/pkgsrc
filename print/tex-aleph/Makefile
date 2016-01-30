# $NetBSD: Makefile,v 1.2 2016/01/30 03:26:06 markd Exp $

DISTNAME=	aleph
PKGNAME=	tex-${DISTNAME}-0.2
TEXLIVE_REV=	33736

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extended TeX
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-bin<=3.0nb57
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-plain>=3.141592653nb2:../../print/tex-plain
DEPENDS+=	tex-lambda>=2014:../../print/tex-lambda
DEPENDS+=	web2c>=2014:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"aleph aleph - *aleph.ini\\nlamed aleph language.dat *lambda.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf aleph ${DESTDIR}${PREFIX}/bin/lamed

.include "../../mk/bsd.pkg.mk"
