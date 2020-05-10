# $NetBSD: Makefile,v 1.7 2020/05/10 04:31:57 markd Exp $

DISTNAME=	aleph
PKGNAME=	tex-${DISTNAME}-0.2.54276
PKGREVISION=	1
TEXLIVE_REV=	54276

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/aleph
COMMENT=	Extended TeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-omega-[0-9]*:../../print/tex-omega
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
